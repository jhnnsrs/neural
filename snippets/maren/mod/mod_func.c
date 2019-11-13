#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," IKd_traub.mod");
fprintf(stderr," IM.mod");
fprintf(stderr," INa_traub_shifted.mod");
fprintf(stderr," cad.mod");
fprintf(stderr," cagk.mod");
fprintf(stderr," cal.mod");
fprintf(stderr," calH.mod");
fprintf(stderr," car.mod");
fprintf(stderr," cat.mod");
fprintf(stderr," hNa.mod");
fprintf(stderr," hha2.mod");
fprintf(stderr," hha_old.mod");
fprintf(stderr," kad.mod");
fprintf(stderr," kap.mod");
fprintf(stderr," kca.mod");
fprintf(stderr," nap.mod");
fprintf(stderr," somacar.mod");
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
