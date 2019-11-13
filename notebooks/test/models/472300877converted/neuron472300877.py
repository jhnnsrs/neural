'''
Defines a class, Neuron472300877, of neurons from Allen Brain Institute's model 472300877

A demo is available by running:

    python -i mosinit.py
'''
class Neuron472300877:
    def __init__(self, name="Neuron472300877", x=0, y=0, z=0):
        '''Instantiate Neuron472300877.
        
        Parameters:
            x, y, z -- position offset
            
        Note: if name is not specified, Neuron472300877_instance is used instead
        '''
        
        # load the morphology
        from load_swc import load_swc
        load_swc('Scnn1a-Tg2-Cre_Ai14_IVSCC_-171062.06.02.01_470548707_m.swc', self,
                 use_axon=False, xshift=x, yshift=y, zshift=z)

        # custom axon (works because dropping axon during import)
        from neuron import h
        self.axon = [h.Section(cell=self, name='axon[0]'),
                     h.Section(cell=self, name='axon[1]')]
        for sec in self.axon:
            sec.L = 30
            sec.diam = 1
            sec.nseg = 1
        self.axon[0].connect(self.soma[0](0.5))
        self.axon[1].connect(self.axon[0](1))
        self.all += self.axon
        
        self._name = name
        self._insert_mechanisms()
        self._discretize_model()
        self._set_mechanism_parameters()
    
    def __str__(self):
        if self._name is not None:
            return self._name
        else:
            return "Neuron472300877_instance"
                
    def _insert_mechanisms(self):
        from neuron import h
        for sec in self.all:
            sec.insert("pas")
        for mech in [u'CaDynamics', u'Ca_HVA', u'Ca_LVA', u'Ih', u'Im', u'K_P', u'K_T', u'Kv3_1', u'NaTs', u'Nap', u'SK']:
            self.soma[0].insert(mech)
    
    def _set_mechanism_parameters(self):
        from neuron import h
        for sec in self.all:
            sec.Ra = 100.0
            sec.e_pas = -89.2530822754
        for sec in self.apic:
            sec.cm = 2.0
            sec.g_pas = 0.00088404090614
        for sec in self.axon:
            sec.cm = 1.0
            sec.g_pas = 2.50940309503e-05
        for sec in self.dend:
            sec.cm = 2.0
            sec.g_pas = 1.18512909798e-05
        for sec in self.soma:
            sec.cm = 1.0
            sec.ena = 53.0
            sec.ek = -107.0
            sec.gbar_Im = 0.00740183
            sec.gbar_Ih = 8.82112e-05
            sec.gbar_NaTs = 0.154942
            sec.gbar_Nap = 0.00138034
            sec.gbar_K_P = 0.00821774
            sec.gbar_K_T = 3.5924e-06
            sec.gbar_SK = 0.000121983
            sec.gbar_Kv3_1 = 0.192745
            sec.gbar_Ca_HVA = 0.000488045
            sec.gbar_Ca_LVA = 0.00469283
            sec.gamma_CaDynamics = 0.00389576
            sec.decay_CaDynamics = 666.853
            sec.g_pas = 1.42922e-05
    
    def _discretize_model(self):
        for sec in self.all:
            sec.nseg = 1 + 2 * int(sec.L / 40)

