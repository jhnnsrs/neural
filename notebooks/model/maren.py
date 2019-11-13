from neuron import h, gui
import constants


class AISModel(object):
    """Two-section cell: A soma with active channels and
    a dendrite with passive properties."""
    def __init__(self):
        self.create_sections()
        self.build_topology()
        self.build_subsets()
        self.define_geometry()
        self.define_biophysics()
    #
    def create_sections(self):
        """Create the sections of the cell."""
        # NOTE: cell=self is required to tell NEURON of this object.
        self.soma = h.Section(name='soma', cell=self)
        self.dend = h.Section(name='dend', cell=self)
    #
    def build_topology(self):
        """Connect the sections of the cell to build a tree."""
        self.dend.connect(self.soma(1))
    #
    def define_geometry(self):
        """Set the 3D geometry of the cell."""
        self.soma.L = constants.SOMA_LENGTH
        self.soma.diam = constants.SOMA_DIAM


        self.dend.L = 200                      # microns
        self.dend.diam = 1                     # microns
        self.dend.nseg = 5
        h.define_shape() # Translate into 3D points.
    #
    def define_biophysics(self):
        """Assign the membrane properties across the cell."""
        for sec in self.all: # 'all' defined in build_subsets
            sec.Ra = 100    # Axial resistance in Ohm * cm
            sec.cm = 1      # Membrane capacitance in micro Farads / cm^2
        # Insert active Hodgkin-Huxley current in the soma


        self.soma.insert('hh')
        for seg in self.soma:
            seg.hh.gnabar = constants.HH_GNABAR  # Sodium conductance in S/cm2
            seg.hh.gkbar = constants.HH_GKBAR  # Potassium conductance in S/cm2
            seg.hh.gl = constants.HH_GL    # Leak conductance in S/cm2
            seg.hh.el = constants.HH_EL     # Reversal potential in mV



        # Insert passive current in the dendrite
        self.dend.insert('pas')
        self.dend.insert('cad')
        for seg in self.dend:
            seg.pas.g = constants.PAS_G
            seg.pas.e = constants.PAS_E
        
        
    #
    def build_subsets(self):
        """Build subset lists. For now we define 'all'."""
        self.all = h.SectionList()
        self.all.wholetree(sec=self.soma)