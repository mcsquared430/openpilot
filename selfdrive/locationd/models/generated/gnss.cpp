#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2297846703375512046) {
   out_2297846703375512046[0] = delta_x[0] + nom_x[0];
   out_2297846703375512046[1] = delta_x[1] + nom_x[1];
   out_2297846703375512046[2] = delta_x[2] + nom_x[2];
   out_2297846703375512046[3] = delta_x[3] + nom_x[3];
   out_2297846703375512046[4] = delta_x[4] + nom_x[4];
   out_2297846703375512046[5] = delta_x[5] + nom_x[5];
   out_2297846703375512046[6] = delta_x[6] + nom_x[6];
   out_2297846703375512046[7] = delta_x[7] + nom_x[7];
   out_2297846703375512046[8] = delta_x[8] + nom_x[8];
   out_2297846703375512046[9] = delta_x[9] + nom_x[9];
   out_2297846703375512046[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_111414451545151170) {
   out_111414451545151170[0] = -nom_x[0] + true_x[0];
   out_111414451545151170[1] = -nom_x[1] + true_x[1];
   out_111414451545151170[2] = -nom_x[2] + true_x[2];
   out_111414451545151170[3] = -nom_x[3] + true_x[3];
   out_111414451545151170[4] = -nom_x[4] + true_x[4];
   out_111414451545151170[5] = -nom_x[5] + true_x[5];
   out_111414451545151170[6] = -nom_x[6] + true_x[6];
   out_111414451545151170[7] = -nom_x[7] + true_x[7];
   out_111414451545151170[8] = -nom_x[8] + true_x[8];
   out_111414451545151170[9] = -nom_x[9] + true_x[9];
   out_111414451545151170[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_1712036253867640506) {
   out_1712036253867640506[0] = 1.0;
   out_1712036253867640506[1] = 0;
   out_1712036253867640506[2] = 0;
   out_1712036253867640506[3] = 0;
   out_1712036253867640506[4] = 0;
   out_1712036253867640506[5] = 0;
   out_1712036253867640506[6] = 0;
   out_1712036253867640506[7] = 0;
   out_1712036253867640506[8] = 0;
   out_1712036253867640506[9] = 0;
   out_1712036253867640506[10] = 0;
   out_1712036253867640506[11] = 0;
   out_1712036253867640506[12] = 1.0;
   out_1712036253867640506[13] = 0;
   out_1712036253867640506[14] = 0;
   out_1712036253867640506[15] = 0;
   out_1712036253867640506[16] = 0;
   out_1712036253867640506[17] = 0;
   out_1712036253867640506[18] = 0;
   out_1712036253867640506[19] = 0;
   out_1712036253867640506[20] = 0;
   out_1712036253867640506[21] = 0;
   out_1712036253867640506[22] = 0;
   out_1712036253867640506[23] = 0;
   out_1712036253867640506[24] = 1.0;
   out_1712036253867640506[25] = 0;
   out_1712036253867640506[26] = 0;
   out_1712036253867640506[27] = 0;
   out_1712036253867640506[28] = 0;
   out_1712036253867640506[29] = 0;
   out_1712036253867640506[30] = 0;
   out_1712036253867640506[31] = 0;
   out_1712036253867640506[32] = 0;
   out_1712036253867640506[33] = 0;
   out_1712036253867640506[34] = 0;
   out_1712036253867640506[35] = 0;
   out_1712036253867640506[36] = 1.0;
   out_1712036253867640506[37] = 0;
   out_1712036253867640506[38] = 0;
   out_1712036253867640506[39] = 0;
   out_1712036253867640506[40] = 0;
   out_1712036253867640506[41] = 0;
   out_1712036253867640506[42] = 0;
   out_1712036253867640506[43] = 0;
   out_1712036253867640506[44] = 0;
   out_1712036253867640506[45] = 0;
   out_1712036253867640506[46] = 0;
   out_1712036253867640506[47] = 0;
   out_1712036253867640506[48] = 1.0;
   out_1712036253867640506[49] = 0;
   out_1712036253867640506[50] = 0;
   out_1712036253867640506[51] = 0;
   out_1712036253867640506[52] = 0;
   out_1712036253867640506[53] = 0;
   out_1712036253867640506[54] = 0;
   out_1712036253867640506[55] = 0;
   out_1712036253867640506[56] = 0;
   out_1712036253867640506[57] = 0;
   out_1712036253867640506[58] = 0;
   out_1712036253867640506[59] = 0;
   out_1712036253867640506[60] = 1.0;
   out_1712036253867640506[61] = 0;
   out_1712036253867640506[62] = 0;
   out_1712036253867640506[63] = 0;
   out_1712036253867640506[64] = 0;
   out_1712036253867640506[65] = 0;
   out_1712036253867640506[66] = 0;
   out_1712036253867640506[67] = 0;
   out_1712036253867640506[68] = 0;
   out_1712036253867640506[69] = 0;
   out_1712036253867640506[70] = 0;
   out_1712036253867640506[71] = 0;
   out_1712036253867640506[72] = 1.0;
   out_1712036253867640506[73] = 0;
   out_1712036253867640506[74] = 0;
   out_1712036253867640506[75] = 0;
   out_1712036253867640506[76] = 0;
   out_1712036253867640506[77] = 0;
   out_1712036253867640506[78] = 0;
   out_1712036253867640506[79] = 0;
   out_1712036253867640506[80] = 0;
   out_1712036253867640506[81] = 0;
   out_1712036253867640506[82] = 0;
   out_1712036253867640506[83] = 0;
   out_1712036253867640506[84] = 1.0;
   out_1712036253867640506[85] = 0;
   out_1712036253867640506[86] = 0;
   out_1712036253867640506[87] = 0;
   out_1712036253867640506[88] = 0;
   out_1712036253867640506[89] = 0;
   out_1712036253867640506[90] = 0;
   out_1712036253867640506[91] = 0;
   out_1712036253867640506[92] = 0;
   out_1712036253867640506[93] = 0;
   out_1712036253867640506[94] = 0;
   out_1712036253867640506[95] = 0;
   out_1712036253867640506[96] = 1.0;
   out_1712036253867640506[97] = 0;
   out_1712036253867640506[98] = 0;
   out_1712036253867640506[99] = 0;
   out_1712036253867640506[100] = 0;
   out_1712036253867640506[101] = 0;
   out_1712036253867640506[102] = 0;
   out_1712036253867640506[103] = 0;
   out_1712036253867640506[104] = 0;
   out_1712036253867640506[105] = 0;
   out_1712036253867640506[106] = 0;
   out_1712036253867640506[107] = 0;
   out_1712036253867640506[108] = 1.0;
   out_1712036253867640506[109] = 0;
   out_1712036253867640506[110] = 0;
   out_1712036253867640506[111] = 0;
   out_1712036253867640506[112] = 0;
   out_1712036253867640506[113] = 0;
   out_1712036253867640506[114] = 0;
   out_1712036253867640506[115] = 0;
   out_1712036253867640506[116] = 0;
   out_1712036253867640506[117] = 0;
   out_1712036253867640506[118] = 0;
   out_1712036253867640506[119] = 0;
   out_1712036253867640506[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_2420600810694362224) {
   out_2420600810694362224[0] = dt*state[3] + state[0];
   out_2420600810694362224[1] = dt*state[4] + state[1];
   out_2420600810694362224[2] = dt*state[5] + state[2];
   out_2420600810694362224[3] = state[3];
   out_2420600810694362224[4] = state[4];
   out_2420600810694362224[5] = state[5];
   out_2420600810694362224[6] = dt*state[7] + state[6];
   out_2420600810694362224[7] = dt*state[8] + state[7];
   out_2420600810694362224[8] = state[8];
   out_2420600810694362224[9] = state[9];
   out_2420600810694362224[10] = state[10];
}
void F_fun(double *state, double dt, double *out_4114427183775962978) {
   out_4114427183775962978[0] = 1;
   out_4114427183775962978[1] = 0;
   out_4114427183775962978[2] = 0;
   out_4114427183775962978[3] = dt;
   out_4114427183775962978[4] = 0;
   out_4114427183775962978[5] = 0;
   out_4114427183775962978[6] = 0;
   out_4114427183775962978[7] = 0;
   out_4114427183775962978[8] = 0;
   out_4114427183775962978[9] = 0;
   out_4114427183775962978[10] = 0;
   out_4114427183775962978[11] = 0;
   out_4114427183775962978[12] = 1;
   out_4114427183775962978[13] = 0;
   out_4114427183775962978[14] = 0;
   out_4114427183775962978[15] = dt;
   out_4114427183775962978[16] = 0;
   out_4114427183775962978[17] = 0;
   out_4114427183775962978[18] = 0;
   out_4114427183775962978[19] = 0;
   out_4114427183775962978[20] = 0;
   out_4114427183775962978[21] = 0;
   out_4114427183775962978[22] = 0;
   out_4114427183775962978[23] = 0;
   out_4114427183775962978[24] = 1;
   out_4114427183775962978[25] = 0;
   out_4114427183775962978[26] = 0;
   out_4114427183775962978[27] = dt;
   out_4114427183775962978[28] = 0;
   out_4114427183775962978[29] = 0;
   out_4114427183775962978[30] = 0;
   out_4114427183775962978[31] = 0;
   out_4114427183775962978[32] = 0;
   out_4114427183775962978[33] = 0;
   out_4114427183775962978[34] = 0;
   out_4114427183775962978[35] = 0;
   out_4114427183775962978[36] = 1;
   out_4114427183775962978[37] = 0;
   out_4114427183775962978[38] = 0;
   out_4114427183775962978[39] = 0;
   out_4114427183775962978[40] = 0;
   out_4114427183775962978[41] = 0;
   out_4114427183775962978[42] = 0;
   out_4114427183775962978[43] = 0;
   out_4114427183775962978[44] = 0;
   out_4114427183775962978[45] = 0;
   out_4114427183775962978[46] = 0;
   out_4114427183775962978[47] = 0;
   out_4114427183775962978[48] = 1;
   out_4114427183775962978[49] = 0;
   out_4114427183775962978[50] = 0;
   out_4114427183775962978[51] = 0;
   out_4114427183775962978[52] = 0;
   out_4114427183775962978[53] = 0;
   out_4114427183775962978[54] = 0;
   out_4114427183775962978[55] = 0;
   out_4114427183775962978[56] = 0;
   out_4114427183775962978[57] = 0;
   out_4114427183775962978[58] = 0;
   out_4114427183775962978[59] = 0;
   out_4114427183775962978[60] = 1;
   out_4114427183775962978[61] = 0;
   out_4114427183775962978[62] = 0;
   out_4114427183775962978[63] = 0;
   out_4114427183775962978[64] = 0;
   out_4114427183775962978[65] = 0;
   out_4114427183775962978[66] = 0;
   out_4114427183775962978[67] = 0;
   out_4114427183775962978[68] = 0;
   out_4114427183775962978[69] = 0;
   out_4114427183775962978[70] = 0;
   out_4114427183775962978[71] = 0;
   out_4114427183775962978[72] = 1;
   out_4114427183775962978[73] = dt;
   out_4114427183775962978[74] = 0;
   out_4114427183775962978[75] = 0;
   out_4114427183775962978[76] = 0;
   out_4114427183775962978[77] = 0;
   out_4114427183775962978[78] = 0;
   out_4114427183775962978[79] = 0;
   out_4114427183775962978[80] = 0;
   out_4114427183775962978[81] = 0;
   out_4114427183775962978[82] = 0;
   out_4114427183775962978[83] = 0;
   out_4114427183775962978[84] = 1;
   out_4114427183775962978[85] = dt;
   out_4114427183775962978[86] = 0;
   out_4114427183775962978[87] = 0;
   out_4114427183775962978[88] = 0;
   out_4114427183775962978[89] = 0;
   out_4114427183775962978[90] = 0;
   out_4114427183775962978[91] = 0;
   out_4114427183775962978[92] = 0;
   out_4114427183775962978[93] = 0;
   out_4114427183775962978[94] = 0;
   out_4114427183775962978[95] = 0;
   out_4114427183775962978[96] = 1;
   out_4114427183775962978[97] = 0;
   out_4114427183775962978[98] = 0;
   out_4114427183775962978[99] = 0;
   out_4114427183775962978[100] = 0;
   out_4114427183775962978[101] = 0;
   out_4114427183775962978[102] = 0;
   out_4114427183775962978[103] = 0;
   out_4114427183775962978[104] = 0;
   out_4114427183775962978[105] = 0;
   out_4114427183775962978[106] = 0;
   out_4114427183775962978[107] = 0;
   out_4114427183775962978[108] = 1;
   out_4114427183775962978[109] = 0;
   out_4114427183775962978[110] = 0;
   out_4114427183775962978[111] = 0;
   out_4114427183775962978[112] = 0;
   out_4114427183775962978[113] = 0;
   out_4114427183775962978[114] = 0;
   out_4114427183775962978[115] = 0;
   out_4114427183775962978[116] = 0;
   out_4114427183775962978[117] = 0;
   out_4114427183775962978[118] = 0;
   out_4114427183775962978[119] = 0;
   out_4114427183775962978[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_2949676141157986562) {
   out_2949676141157986562[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_6630096978930967114) {
   out_6630096978930967114[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6630096978930967114[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6630096978930967114[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6630096978930967114[3] = 0;
   out_6630096978930967114[4] = 0;
   out_6630096978930967114[5] = 0;
   out_6630096978930967114[6] = 1;
   out_6630096978930967114[7] = 0;
   out_6630096978930967114[8] = 0;
   out_6630096978930967114[9] = 0;
   out_6630096978930967114[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_4956105181449293521) {
   out_4956105181449293521[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_3156613020081298281) {
   out_3156613020081298281[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3156613020081298281[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3156613020081298281[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3156613020081298281[3] = 0;
   out_3156613020081298281[4] = 0;
   out_3156613020081298281[5] = 0;
   out_3156613020081298281[6] = 1;
   out_3156613020081298281[7] = 0;
   out_3156613020081298281[8] = 0;
   out_3156613020081298281[9] = 1;
   out_3156613020081298281[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_2199945742104997938) {
   out_2199945742104997938[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_5021442328268011661) {
   out_5021442328268011661[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[6] = 0;
   out_5021442328268011661[7] = 1;
   out_5021442328268011661[8] = 0;
   out_5021442328268011661[9] = 0;
   out_5021442328268011661[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_2199945742104997938) {
   out_2199945742104997938[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_5021442328268011661) {
   out_5021442328268011661[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_5021442328268011661[6] = 0;
   out_5021442328268011661[7] = 1;
   out_5021442328268011661[8] = 0;
   out_5021442328268011661[9] = 0;
   out_5021442328268011661[10] = 0;
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

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2297846703375512046) {
  err_fun(nom_x, delta_x, out_2297846703375512046);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_111414451545151170) {
  inv_err_fun(nom_x, true_x, out_111414451545151170);
}
void gnss_H_mod_fun(double *state, double *out_1712036253867640506) {
  H_mod_fun(state, out_1712036253867640506);
}
void gnss_f_fun(double *state, double dt, double *out_2420600810694362224) {
  f_fun(state,  dt, out_2420600810694362224);
}
void gnss_F_fun(double *state, double dt, double *out_4114427183775962978) {
  F_fun(state,  dt, out_4114427183775962978);
}
void gnss_h_6(double *state, double *sat_pos, double *out_2949676141157986562) {
  h_6(state, sat_pos, out_2949676141157986562);
}
void gnss_H_6(double *state, double *sat_pos, double *out_6630096978930967114) {
  H_6(state, sat_pos, out_6630096978930967114);
}
void gnss_h_20(double *state, double *sat_pos, double *out_4956105181449293521) {
  h_20(state, sat_pos, out_4956105181449293521);
}
void gnss_H_20(double *state, double *sat_pos, double *out_3156613020081298281) {
  H_20(state, sat_pos, out_3156613020081298281);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2199945742104997938) {
  h_7(state, sat_pos_vel, out_2199945742104997938);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_5021442328268011661) {
  H_7(state, sat_pos_vel, out_5021442328268011661);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2199945742104997938) {
  h_21(state, sat_pos_vel, out_2199945742104997938);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_5021442328268011661) {
  H_21(state, sat_pos_vel, out_5021442328268011661);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
