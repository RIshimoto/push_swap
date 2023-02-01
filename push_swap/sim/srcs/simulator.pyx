import torch
cimport simulator as sim

cdef sim.t_stacks* _list2stks(list args):
    cdef sim.t_stacks *stks 

    stks = sim.stks_init()
    if stks == NULL:
        raise MemoryError()
    for num in args[::-1]:
        sim.stk_push(stks.stk_a, num)
    return stks

cdef class State:
    cdef sim.t_stacks *_stks

    def __cinit__(self):
        pass

    def __dealloc__(self):
        pass

    def __str__(self):
        sim.stks_print(self._stks)
        return ""

    cdef setup(self, sim.t_stacks *stks):
        self._stks = stks

    cdef step(self, char *action):
        sim.exec_instruction(action, &self._stks);

    cdef free(self):
        sim.stks_free(&self._stks)

    cdef is_done(self):
        return sim.checker(self._stks) 

    cdef clone(self):
        cdef State state

        state = State()
        state.setup(sim.stks_copy(self._stks))
        return state

cdef class PushSwap:
    cdef: 
        State _state
        list args
    
    def __cinit__(self, list args):
        assert len(set(args)) == len(args)
        self.args = args
        self._state = State()
        self._state.setup(_list2stks(self.args))

    def __dealloc__(self):
        pass

    cpdef reset(self):
        self._state.free()
        self._state = State()
        self._state.setup(_list2stks(self.args))
        return self._state

    cpdef step(self, action):
        cdef:
            State state
            int is_done
            double reward
            char *_action

        action = action.encode('UTF-8')
        _action = action
        self._state.step(_action)
        state = self._state.clone()
        is_done = self._state.is_done()
        reward = 0.0 if is_done else -1.0
        return (state, reward, is_done)
