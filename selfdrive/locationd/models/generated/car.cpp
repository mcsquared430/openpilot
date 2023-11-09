#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1131633148622044353) {
   out_1131633148622044353[0] = delta_x[0] + nom_x[0];
   out_1131633148622044353[1] = delta_x[1] + nom_x[1];
   out_1131633148622044353[2] = delta_x[2] + nom_x[2];
   out_1131633148622044353[3] = delta_x[3] + nom_x[3];
   out_1131633148622044353[4] = delta_x[4] + nom_x[4];
   out_1131633148622044353[5] = delta_x[5] + nom_x[5];
   out_1131633148622044353[6] = delta_x[6] + nom_x[6];
   out_1131633148622044353[7] = delta_x[7] + nom_x[7];
   out_1131633148622044353[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4783059866425263319) {
   out_4783059866425263319[0] = -nom_x[0] + true_x[0];
   out_4783059866425263319[1] = -nom_x[1] + true_x[1];
   out_4783059866425263319[2] = -nom_x[2] + true_x[2];
   out_4783059866425263319[3] = -nom_x[3] + true_x[3];
   out_4783059866425263319[4] = -nom_x[4] + true_x[4];
   out_4783059866425263319[5] = -nom_x[5] + true_x[5];
   out_4783059866425263319[6] = -nom_x[6] + true_x[6];
   out_4783059866425263319[7] = -nom_x[7] + true_x[7];
   out_4783059866425263319[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2331702352123017189) {
   out_2331702352123017189[0] = 1.0;
   out_2331702352123017189[1] = 0;
   out_2331702352123017189[2] = 0;
   out_2331702352123017189[3] = 0;
   out_2331702352123017189[4] = 0;
   out_2331702352123017189[5] = 0;
   out_2331702352123017189[6] = 0;
   out_2331702352123017189[7] = 0;
   out_2331702352123017189[8] = 0;
   out_2331702352123017189[9] = 0;
   out_2331702352123017189[10] = 1.0;
   out_2331702352123017189[11] = 0;
   out_2331702352123017189[12] = 0;
   out_2331702352123017189[13] = 0;
   out_2331702352123017189[14] = 0;
   out_2331702352123017189[15] = 0;
   out_2331702352123017189[16] = 0;
   out_2331702352123017189[17] = 0;
   out_2331702352123017189[18] = 0;
   out_2331702352123017189[19] = 0;
   out_2331702352123017189[20] = 1.0;
   out_2331702352123017189[21] = 0;
   out_2331702352123017189[22] = 0;
   out_2331702352123017189[23] = 0;
   out_2331702352123017189[24] = 0;
   out_2331702352123017189[25] = 0;
   out_2331702352123017189[26] = 0;
   out_2331702352123017189[27] = 0;
   out_2331702352123017189[28] = 0;
   out_2331702352123017189[29] = 0;
   out_2331702352123017189[30] = 1.0;
   out_2331702352123017189[31] = 0;
   out_2331702352123017189[32] = 0;
   out_2331702352123017189[33] = 0;
   out_2331702352123017189[34] = 0;
   out_2331702352123017189[35] = 0;
   out_2331702352123017189[36] = 0;
   out_2331702352123017189[37] = 0;
   out_2331702352123017189[38] = 0;
   out_2331702352123017189[39] = 0;
   out_2331702352123017189[40] = 1.0;
   out_2331702352123017189[41] = 0;
   out_2331702352123017189[42] = 0;
   out_2331702352123017189[43] = 0;
   out_2331702352123017189[44] = 0;
   out_2331702352123017189[45] = 0;
   out_2331702352123017189[46] = 0;
   out_2331702352123017189[47] = 0;
   out_2331702352123017189[48] = 0;
   out_2331702352123017189[49] = 0;
   out_2331702352123017189[50] = 1.0;
   out_2331702352123017189[51] = 0;
   out_2331702352123017189[52] = 0;
   out_2331702352123017189[53] = 0;
   out_2331702352123017189[54] = 0;
   out_2331702352123017189[55] = 0;
   out_2331702352123017189[56] = 0;
   out_2331702352123017189[57] = 0;
   out_2331702352123017189[58] = 0;
   out_2331702352123017189[59] = 0;
   out_2331702352123017189[60] = 1.0;
   out_2331702352123017189[61] = 0;
   out_2331702352123017189[62] = 0;
   out_2331702352123017189[63] = 0;
   out_2331702352123017189[64] = 0;
   out_2331702352123017189[65] = 0;
   out_2331702352123017189[66] = 0;
   out_2331702352123017189[67] = 0;
   out_2331702352123017189[68] = 0;
   out_2331702352123017189[69] = 0;
   out_2331702352123017189[70] = 1.0;
   out_2331702352123017189[71] = 0;
   out_2331702352123017189[72] = 0;
   out_2331702352123017189[73] = 0;
   out_2331702352123017189[74] = 0;
   out_2331702352123017189[75] = 0;
   out_2331702352123017189[76] = 0;
   out_2331702352123017189[77] = 0;
   out_2331702352123017189[78] = 0;
   out_2331702352123017189[79] = 0;
   out_2331702352123017189[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2982802491591513526) {
   out_2982802491591513526[0] = state[0];
   out_2982802491591513526[1] = state[1];
   out_2982802491591513526[2] = state[2];
   out_2982802491591513526[3] = state[3];
   out_2982802491591513526[4] = state[4];
   out_2982802491591513526[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2982802491591513526[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2982802491591513526[7] = state[7];
   out_2982802491591513526[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2718516796934112193) {
   out_2718516796934112193[0] = 1;
   out_2718516796934112193[1] = 0;
   out_2718516796934112193[2] = 0;
   out_2718516796934112193[3] = 0;
   out_2718516796934112193[4] = 0;
   out_2718516796934112193[5] = 0;
   out_2718516796934112193[6] = 0;
   out_2718516796934112193[7] = 0;
   out_2718516796934112193[8] = 0;
   out_2718516796934112193[9] = 0;
   out_2718516796934112193[10] = 1;
   out_2718516796934112193[11] = 0;
   out_2718516796934112193[12] = 0;
   out_2718516796934112193[13] = 0;
   out_2718516796934112193[14] = 0;
   out_2718516796934112193[15] = 0;
   out_2718516796934112193[16] = 0;
   out_2718516796934112193[17] = 0;
   out_2718516796934112193[18] = 0;
   out_2718516796934112193[19] = 0;
   out_2718516796934112193[20] = 1;
   out_2718516796934112193[21] = 0;
   out_2718516796934112193[22] = 0;
   out_2718516796934112193[23] = 0;
   out_2718516796934112193[24] = 0;
   out_2718516796934112193[25] = 0;
   out_2718516796934112193[26] = 0;
   out_2718516796934112193[27] = 0;
   out_2718516796934112193[28] = 0;
   out_2718516796934112193[29] = 0;
   out_2718516796934112193[30] = 1;
   out_2718516796934112193[31] = 0;
   out_2718516796934112193[32] = 0;
   out_2718516796934112193[33] = 0;
   out_2718516796934112193[34] = 0;
   out_2718516796934112193[35] = 0;
   out_2718516796934112193[36] = 0;
   out_2718516796934112193[37] = 0;
   out_2718516796934112193[38] = 0;
   out_2718516796934112193[39] = 0;
   out_2718516796934112193[40] = 1;
   out_2718516796934112193[41] = 0;
   out_2718516796934112193[42] = 0;
   out_2718516796934112193[43] = 0;
   out_2718516796934112193[44] = 0;
   out_2718516796934112193[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2718516796934112193[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2718516796934112193[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2718516796934112193[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2718516796934112193[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2718516796934112193[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2718516796934112193[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2718516796934112193[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2718516796934112193[53] = -9.8000000000000007*dt;
   out_2718516796934112193[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2718516796934112193[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2718516796934112193[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2718516796934112193[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2718516796934112193[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2718516796934112193[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2718516796934112193[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2718516796934112193[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2718516796934112193[62] = 0;
   out_2718516796934112193[63] = 0;
   out_2718516796934112193[64] = 0;
   out_2718516796934112193[65] = 0;
   out_2718516796934112193[66] = 0;
   out_2718516796934112193[67] = 0;
   out_2718516796934112193[68] = 0;
   out_2718516796934112193[69] = 0;
   out_2718516796934112193[70] = 1;
   out_2718516796934112193[71] = 0;
   out_2718516796934112193[72] = 0;
   out_2718516796934112193[73] = 0;
   out_2718516796934112193[74] = 0;
   out_2718516796934112193[75] = 0;
   out_2718516796934112193[76] = 0;
   out_2718516796934112193[77] = 0;
   out_2718516796934112193[78] = 0;
   out_2718516796934112193[79] = 0;
   out_2718516796934112193[80] = 1;
}
void h_25(double *state, double *unused, double *out_98312232782489881) {
   out_98312232782489881[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7415434730998619595) {
   out_7415434730998619595[0] = 0;
   out_7415434730998619595[1] = 0;
   out_7415434730998619595[2] = 0;
   out_7415434730998619595[3] = 0;
   out_7415434730998619595[4] = 0;
   out_7415434730998619595[5] = 0;
   out_7415434730998619595[6] = 1;
   out_7415434730998619595[7] = 0;
   out_7415434730998619595[8] = 0;
}
void h_24(double *state, double *unused, double *out_2215448414604224264) {
   out_2215448414604224264[0] = state[4];
   out_2215448414604224264[1] = state[5];
}
void H_24(double *state, double *unused, double *out_839862924407101494) {
   out_839862924407101494[0] = 0;
   out_839862924407101494[1] = 0;
   out_839862924407101494[2] = 0;
   out_839862924407101494[3] = 0;
   out_839862924407101494[4] = 1;
   out_839862924407101494[5] = 0;
   out_839862924407101494[6] = 0;
   out_839862924407101494[7] = 0;
   out_839862924407101494[8] = 0;
   out_839862924407101494[9] = 0;
   out_839862924407101494[10] = 0;
   out_839862924407101494[11] = 0;
   out_839862924407101494[12] = 0;
   out_839862924407101494[13] = 0;
   out_839862924407101494[14] = 1;
   out_839862924407101494[15] = 0;
   out_839862924407101494[16] = 0;
   out_839862924407101494[17] = 0;
}
void h_30(double *state, double *unused, double *out_19598108828665550) {
   out_19598108828665550[0] = state[4];
}
void H_30(double *state, double *unused, double *out_498744389507002840) {
   out_498744389507002840[0] = 0;
   out_498744389507002840[1] = 0;
   out_498744389507002840[2] = 0;
   out_498744389507002840[3] = 0;
   out_498744389507002840[4] = 1;
   out_498744389507002840[5] = 0;
   out_498744389507002840[6] = 0;
   out_498744389507002840[7] = 0;
   out_498744389507002840[8] = 0;
}
void h_26(double *state, double *unused, double *out_5729013140666198620) {
   out_5729013140666198620[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7289806023836875797) {
   out_7289806023836875797[0] = 0;
   out_7289806023836875797[1] = 0;
   out_7289806023836875797[2] = 0;
   out_7289806023836875797[3] = 0;
   out_7289806023836875797[4] = 0;
   out_7289806023836875797[5] = 0;
   out_7289806023836875797[6] = 0;
   out_7289806023836875797[7] = 1;
   out_7289806023836875797[8] = 0;
}
void h_27(double *state, double *unused, double *out_5099985500443335526) {
   out_5099985500443335526[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2673507701307427751) {
   out_2673507701307427751[0] = 0;
   out_2673507701307427751[1] = 0;
   out_2673507701307427751[2] = 0;
   out_2673507701307427751[3] = 1;
   out_2673507701307427751[4] = 0;
   out_2673507701307427751[5] = 0;
   out_2673507701307427751[6] = 0;
   out_2673507701307427751[7] = 0;
   out_2673507701307427751[8] = 0;
}
void h_29(double *state, double *unused, double *out_8737435028697357876) {
   out_8737435028697357876[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4386870428176978784) {
   out_4386870428176978784[0] = 0;
   out_4386870428176978784[1] = 1;
   out_4386870428176978784[2] = 0;
   out_4386870428176978784[3] = 0;
   out_4386870428176978784[4] = 0;
   out_4386870428176978784[5] = 0;
   out_4386870428176978784[6] = 0;
   out_4386870428176978784[7] = 0;
   out_4386870428176978784[8] = 0;
}
void h_28(double *state, double *unused, double *out_2063199448999002841) {
   out_2063199448999002841[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8977474628463042258) {
   out_8977474628463042258[0] = 1;
   out_8977474628463042258[1] = 0;
   out_8977474628463042258[2] = 0;
   out_8977474628463042258[3] = 0;
   out_8977474628463042258[4] = 0;
   out_8977474628463042258[5] = 0;
   out_8977474628463042258[6] = 0;
   out_8977474628463042258[7] = 0;
   out_8977474628463042258[8] = 0;
}
void h_31(double *state, double *unused, double *out_3763371243646011771) {
   out_3763371243646011771[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7384788769121659167) {
   out_7384788769121659167[0] = 0;
   out_7384788769121659167[1] = 0;
   out_7384788769121659167[2] = 0;
   out_7384788769121659167[3] = 0;
   out_7384788769121659167[4] = 0;
   out_7384788769121659167[5] = 0;
   out_7384788769121659167[6] = 0;
   out_7384788769121659167[7] = 0;
   out_7384788769121659167[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1131633148622044353) {
  err_fun(nom_x, delta_x, out_1131633148622044353);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4783059866425263319) {
  inv_err_fun(nom_x, true_x, out_4783059866425263319);
}
void car_H_mod_fun(double *state, double *out_2331702352123017189) {
  H_mod_fun(state, out_2331702352123017189);
}
void car_f_fun(double *state, double dt, double *out_2982802491591513526) {
  f_fun(state,  dt, out_2982802491591513526);
}
void car_F_fun(double *state, double dt, double *out_2718516796934112193) {
  F_fun(state,  dt, out_2718516796934112193);
}
void car_h_25(double *state, double *unused, double *out_98312232782489881) {
  h_25(state, unused, out_98312232782489881);
}
void car_H_25(double *state, double *unused, double *out_7415434730998619595) {
  H_25(state, unused, out_7415434730998619595);
}
void car_h_24(double *state, double *unused, double *out_2215448414604224264) {
  h_24(state, unused, out_2215448414604224264);
}
void car_H_24(double *state, double *unused, double *out_839862924407101494) {
  H_24(state, unused, out_839862924407101494);
}
void car_h_30(double *state, double *unused, double *out_19598108828665550) {
  h_30(state, unused, out_19598108828665550);
}
void car_H_30(double *state, double *unused, double *out_498744389507002840) {
  H_30(state, unused, out_498744389507002840);
}
void car_h_26(double *state, double *unused, double *out_5729013140666198620) {
  h_26(state, unused, out_5729013140666198620);
}
void car_H_26(double *state, double *unused, double *out_7289806023836875797) {
  H_26(state, unused, out_7289806023836875797);
}
void car_h_27(double *state, double *unused, double *out_5099985500443335526) {
  h_27(state, unused, out_5099985500443335526);
}
void car_H_27(double *state, double *unused, double *out_2673507701307427751) {
  H_27(state, unused, out_2673507701307427751);
}
void car_h_29(double *state, double *unused, double *out_8737435028697357876) {
  h_29(state, unused, out_8737435028697357876);
}
void car_H_29(double *state, double *unused, double *out_4386870428176978784) {
  H_29(state, unused, out_4386870428176978784);
}
void car_h_28(double *state, double *unused, double *out_2063199448999002841) {
  h_28(state, unused, out_2063199448999002841);
}
void car_H_28(double *state, double *unused, double *out_8977474628463042258) {
  H_28(state, unused, out_8977474628463042258);
}
void car_h_31(double *state, double *unused, double *out_3763371243646011771) {
  h_31(state, unused, out_3763371243646011771);
}
void car_H_31(double *state, double *unused, double *out_7384788769121659167) {
  H_31(state, unused, out_7384788769121659167);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
