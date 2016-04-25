#include "d3q15.h"
/* static int complement[DQ_q]; */

void bc_box_init(Lattice *lat) {
  
}


#define isbulk(i) (i[0]>0 && i[0]<n[0]+1 && \
		   i[1]>0 && i[1]<n[1]+1 && \
		   i[2]>0 && i[2]<n[2]+1)

void bc_box_update(Lattice *lat) {
  int i[DQ_d], n[DQ_d];

  n[0] = lat->nx; n[1] = lat->ny; n[2] = lat->nz;
  
  /* XY  walls */
  for (i[DQ_X]=0; i[DQ_X]<=n[DQ_X]+1; i[DQ_X]++) {
    for (i[DQ_Y]=0; i[DQ_Y]<=n[DQ_Y]+1; i[DQ_Y]++) {
      i[DQ_Z] = 0;
      bc_noslip_do_site(lat, i, n);
      i[DQ_Z] = n[DQ_Z] + 1;
      bc_noslip_do_site(lat, i, n);
    }
  }
  /* XZ  walls */
  for (i[DQ_X]=0; i[DQ_X]<=n[DQ_X]+1; i[DQ_X]++) {
    for (i[DQ_Z]=0; i[DQ_Z]<=n[DQ_Z]+1; i[DQ_Z]++) {
      i[DQ_Y] = 0;
      bc_noslip_do_site(lat, i, n);
      i[DQ_Y] = n[DQ_Y] + 1;
      bc_noslip_do_site(lat, i, n);
    }
  }
  /* YZ  walls */
  for (i[DQ_Y]=0; i[DQ_Y]<=n[DQ_Y]+1; i[DQ_Y]++) {
    for (i[DQ_Z]=0; i[DQ_Z]<=n[DQ_Z]+1; i[DQ_Z]++) {
      i[DQ_X] = 0;
      bc_noslip_do_site(lat, i, n);
      i[DQ_X] = n[DQ_X] + 1;
      bc_noslip_do_site(lat, i, n);
    }
  }
}
