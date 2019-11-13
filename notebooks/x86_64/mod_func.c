#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _IKd_traub_reg(void);
extern void _IM_reg(void);
extern void _INa_traub_shifted_reg(void);
extern void _cad_reg(void);
extern void _cagk_reg(void);
extern void _cal_reg(void);
extern void _calH_reg(void);
extern void _car_reg(void);
extern void _cat_reg(void);
extern void _hNa_reg(void);
extern void _hha2_reg(void);
extern void _hha_old_reg(void);
extern void _kad_reg(void);
extern void _kap_reg(void);
extern void _kca_reg(void);
extern void _nap_reg(void);
extern void _somacar_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," mod/IKd_traub.mod");
    fprintf(stderr," mod/IM.mod");
    fprintf(stderr," mod/INa_traub_shifted.mod");
    fprintf(stderr," mod/cad.mod");
    fprintf(stderr," mod/cagk.mod");
    fprintf(stderr," mod/cal.mod");
    fprintf(stderr," mod/calH.mod");
    fprintf(stderr," mod/car.mod");
    fprintf(stderr," mod/cat.mod");
    fprintf(stderr," mod/hNa.mod");
    fprintf(stderr," mod/hha2.mod");
    fprintf(stderr," mod/hha_old.mod");
    fprintf(stderr," mod/kad.mod");
    fprintf(stderr," mod/kap.mod");
    fprintf(stderr," mod/kca.mod");
    fprintf(stderr," mod/nap.mod");
    fprintf(stderr," mod/somacar.mod");
    fprintf(stderr, "\n");
  }
  _IKd_traub_reg();
  _IM_reg();
  _INa_traub_shifted_reg();
  _cad_reg();
  _cagk_reg();
  _cal_reg();
  _calH_reg();
  _car_reg();
  _cat_reg();
  _hNa_reg();
  _hha2_reg();
  _hha_old_reg();
  _kad_reg();
  _kap_reg();
  _kca_reg();
  _nap_reg();
  _somacar_reg();
}
