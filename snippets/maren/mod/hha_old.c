/* Created by Language version: 6.2.0 */
/* NOT VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib.h"
#undef PI
 
#include "md1redef.h"
#include "section.h"
#include "md2redef.h"

#if METHOD3
extern int _method3;
#endif

#undef exp
#define exp hoc_Exp
extern double hoc_Exp();
 
#define _threadargscomma_ /**/
#define _threadargs_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define ar2 _p[0]
#define W _p[1]
#define gnabar _p[2]
#define gkbar _p[3]
#define gl _p[4]
#define el _p[5]
#define il _p[6]
#define inf (_p + 7)
#define fac (_p + 11)
#define tau (_p + 15)
#define m _p[19]
#define h _p[20]
#define n _p[21]
#define s _p[22]
#define ena _p[23]
#define ek _p[24]
#define Dm _p[25]
#define Dh _p[26]
#define Dn _p[27]
#define Ds _p[28]
#define ina _p[29]
#define ik _p[30]
#define _g _p[31]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
#define _ion_ek	*_ppvar[3]._pval
#define _ion_ik	*_ppvar[4]._pval
#define _ion_dikdv	*_ppvar[5]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static int _hoc_alpr();
 static int _hoc_alpv();
 static int _hoc_betr();
 static int _hoc_calcg();
 static int _hoc_mhn();
 static int _hoc_states();
 static int _hoc_vartau();
 static int _hoc_varss();
 static int _mechtype;
extern int nrn_get_mechtype();
 static _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range();
 _prop = hoc_getdata_range(_mechtype);
 _p = _prop->param; _ppvar = _prop->dparam;
 ret(1.);
}
 /* connect user functions to hoc names */
 static IntFunc hoc_intfunc[] = {
 "setdata_hha_old", _hoc_setdata,
 "alpr_hha_old", _hoc_alpr,
 "alpv_hha_old", _hoc_alpv,
 "betr_hha_old", _hoc_betr,
 "calcg_hha_old", _hoc_calcg,
 "mhn_hha_old", _hoc_mhn,
 "states_hha_old", _hoc_states,
 "vartau_hha_old", _hoc_vartau,
 "varss_hha_old", _hoc_varss,
 0, 0
};
#define alpr alpr_hha_old
#define alpv alpv_hha_old
#define betr betr_hha_old
#define vartau vartau_hha_old
#define varss varss_hha_old
 extern double alpr();
 extern double alpv();
 extern double betr();
 extern double vartau();
 extern double varss();
 /* declare global and static user variables */
#define a0r a0r_hha_old
 double a0r = 0.0003;
#define b0r b0r_hha_old
 double b0r = 0.0003;
#define gmr gmr_hha_old
 double gmr = 0.2;
#define taumin taumin_hha_old
 double taumin = 3;
#define vhalfr vhalfr_hha_old
 double vhalfr = -60;
#define vvs vvs_hha_old
 double vvs = 2;
#define zetas zetas_hha_old
 double zetas = 12;
#define zetar zetar_hha_old
 double zetar = 12;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "a0r_hha_old", "ms",
 "b0r_hha_old", "ms",
 "taumin_hha_old", "ms",
 "vvs_hha_old", "mV",
 "vhalfr_hha_old", "mV",
 "W_hha_old", "/mV",
 "gnabar_hha_old", "mho/cm2",
 "gkbar_hha_old", "mho/cm2",
 "gl_hha_old", "mho/cm2",
 "el_hha_old", "mV",
 "il_hha_old", "mA/cm2",
 0,0
};
 static double delta_t = 1;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double s0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "a0r_hha_old", &a0r_hha_old,
 "b0r_hha_old", &b0r_hha_old,
 "zetar_hha_old", &zetar_hha_old,
 "zetas_hha_old", &zetas_hha_old,
 "gmr_hha_old", &gmr_hha_old,
 "taumin_hha_old", &taumin_hha_old,
 "vvs_hha_old", &vvs_hha_old,
 "vhalfr_hha_old", &vhalfr_hha_old,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(), nrn_init(), nrn_state();
 static void nrn_cur(), nrn_jacob();
 
static int _ode_count();
 /* connect range variables in _p that hoc is supposed to know about */
 static char *_mechanism[] = {
 "6.2.0",
"hha_old",
 "ar2_hha_old",
 "W_hha_old",
 "gnabar_hha_old",
 "gkbar_hha_old",
 "gl_hha_old",
 "el_hha_old",
 0,
 "il_hha_old",
 "inf_hha_old[4]",
 "fac_hha_old[4]",
 "tau_hha_old[4]",
 0,
 "m_hha_old",
 "h_hha_old",
 "n_hha_old",
 "s_hha_old",
 0,
 0};
 static Symbol* _na_sym;
 static Symbol* _k_sym;
 
static void nrn_alloc(_prop)
	Prop *_prop;
{
	Prop *prop_ion, *need_memb();
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 32, _prop);
 	/*initialize range parameters*/
 	ar2 = 1;
 	W = 0.016;
 	gnabar = 0;
 	gkbar = 0;
 	gl = 0;
 	el = -70;
 	_prop->param = _p;
 	_prop->param_size = 32;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[3]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[4]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[5]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static _initlists();
 static void _update_ion_pointer(Datum*);
 _hha_old_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("k", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_dparam_size(_mechtype, 6);
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 hha_old /cygdrive/d/NEURON/MODEL_Christian_AcD_ScD_Test/mod/hha_old.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "HH channel that includes both a sodium and a delayed rectifier channel ";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static _modl_cleanup(){ _match_recurse=1;}
static calcg();
static mhn();
static states();
 
static int  calcg (  )  {
   mhn ( _threadargscomma_ v * 1.0 ) ;
   m = m + fac [ 0 ] * ( inf [ 0 ] - m ) ;
   h = h + fac [ 1 ] * ( inf [ 1 ] - h ) ;
   n = n + fac [ 2 ] * ( inf [ 2 ] - n ) ;
   s = s + fac [ 3 ] * ( inf [ 3 ] - s ) ;
    return 0; }
 
static int _hoc_calcg() {
  double _r;
   _r = 1.;
 calcg (  ) ;
 ret(_r);
}
 
static int  states (  )  {
   calcg ( _threadargs_ ) ;
   
/*VERBATIM*/
	return 0;
  return 0; }
 
static int _hoc_states() {
  double _r;
   _r = 1.;
 states (  ) ;
 ret(_r);
}
 
double varss (  _lv , _li )  
	double _lv , _li ;
 {
   double _lvarss;
 if ( _li  == 0.0 ) {
     _lvarss = 1.0 / ( 1.0 + exp ( ( _lv + 40.0 ) / ( - 3.0 ) ) ) ;
     }
   else if ( _li  == 1.0 ) {
     _lvarss = 1.0 / ( 1.0 + exp ( ( _lv + 45.0 ) / ( 3.0 ) ) ) ;
     }
   else if ( _li  == 2.0 ) {
     _lvarss = 1.0 / ( 1.0 + exp ( ( _lv + 42.0 ) / ( - 2.0 ) ) ) ;
     }
   else {
     _lvarss = alpv ( _threadargscomma_ _lv , vhalfr ) ;
     }
   
return _lvarss;
 }
 
static int _hoc_varss() {
  double _r;
   _r =  varss (  *getarg(1) , *getarg(2) ) ;
 ret(_r);
}
 
double alpv (  _lv , _lvh )  
	double _lv , _lvh ;
 {
   double _lalpv;
 _lalpv = ( 1.0 + ar2 * exp ( ( _lv - _lvh ) / vvs ) ) / ( 1.0 + exp ( ( _lv - _lvh ) / vvs ) ) ;
   
return _lalpv;
 }
 
static int _hoc_alpv() {
  double _r;
   _r =  alpv (  *getarg(1) , *getarg(2) ) ;
 ret(_r);
}
 
double alpr (  _lv )  
	double _lv ;
 {
   double _lalpr;
 _lalpr = exp ( 1.e-3 * zetar * ( _lv - vhalfr ) * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lalpr;
 }
 
static int _hoc_alpr() {
  double _r;
   _r =  alpr (  *getarg(1) ) ;
 ret(_r);
}
 
double betr (  _lv )  
	double _lv ;
 {
   double _lbetr;
 _lbetr = exp ( 1.e-3 * zetar * gmr * ( _lv - vhalfr ) * 9.648e4 / ( 8.315 * ( 273.16 + celsius ) ) ) ;
   
return _lbetr;
 }
 
static int _hoc_betr() {
  double _r;
   _r =  betr (  *getarg(1) ) ;
 ret(_r);
}
 
double vartau (  _lv , _li )  
	double _lv , _li ;
 {
   double _lvartau;
 double _ltmp ;
 if ( _li  == 0.0 ) {
     _lvartau = 0.05 ;
     }
   else if ( _li  == 1.0 ) {
     _lvartau = 0.5 ;
     }
   else if ( _li  == 2.0 ) {
     _lvartau = 2.2 ;
     }
   else {
     _ltmp = betr ( _threadargscomma_ _lv ) / ( a0r + b0r * alpr ( _threadargscomma_ _lv ) ) ;
     if ( _ltmp < taumin ) {
       _ltmp = taumin ;
       }
     
/*VERBATIM*/
 _lvartau = _ltmp ;
     }
   
return _lvartau;
 }
 
static int _hoc_vartau() {
  double _r;
   _r =  vartau (  *getarg(1) , *getarg(2) ) ;
 ret(_r);
}
 
static int  mhn (  _lv )  
	double _lv ;
 {
   {int  _li ;for ( _li = 0 ; _li <= 3 ; _li ++ ) {
     tau [ _li ] = vartau ( _threadargscomma_ _lv , ((double) _li ) ) ;
     inf [ _li ] = varss ( _threadargscomma_ _lv , ((double) _li ) ) ;
     fac [ _li ] = ( 1.0 - exp ( - dt / tau [ _li ] ) ) ;
     } }
    return 0; }
 
static int _hoc_mhn() {
  double _r;
   _r = 1.;
 mhn (  *getarg(1) ) ;
 ret(_r);
}
 
static int _ode_count(_type)int _type; { hoc_execerror("hha_old", "cannot be used with CVODE");}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
   nrn_update_ion_pointer(_k_sym, _ppvar, 3, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 4, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 5, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  h = h0;
  m = m0;
  n = n0;
  s = s0;
 {
   states ( _threadargs_ ) ;
   s = 1.0 ;
   ina = gnabar * m * m * h * s * ( v - ena ) ;
   ik = gkbar * n * n * ( v - ek ) ;
   il = gl * ( v - el ) ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ena = _ion_ena;
  ek = _ion_ek;
 initmodel();
  }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   ina = gnabar * m * m * h * s * ( v - ena ) ;
   ik = gkbar * n * n * ( v - ek ) ;
   il = gl * ( v - el ) ;
   }
 _current += ina;
 _current += ik;
 _current += il;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ena = _ion_ena;
  ek = _ion_ek;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
 double _dina;
  _dina = ina;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 ;
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
 double _break, _save;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
  ena = _ion_ena;
  ek = _ion_ek;
 { {
 for (; t < _break; t += dt) {
 error =  states();
 if(error){fprintf(stderr,"at line 69 in file hha_old.mod:\n	SOLVE states\n"); nrn_complain(_p); abort_run(error);}
 
}}
 t = _save;
 }  }}

}

static terminal(){}

static _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}
