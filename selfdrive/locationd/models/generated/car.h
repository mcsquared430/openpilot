#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1131633148622044353);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4783059866425263319);
void car_H_mod_fun(double *state, double *out_2331702352123017189);
void car_f_fun(double *state, double dt, double *out_2982802491591513526);
void car_F_fun(double *state, double dt, double *out_2718516796934112193);
void car_h_25(double *state, double *unused, double *out_98312232782489881);
void car_H_25(double *state, double *unused, double *out_7415434730998619595);
void car_h_24(double *state, double *unused, double *out_2215448414604224264);
void car_H_24(double *state, double *unused, double *out_839862924407101494);
void car_h_30(double *state, double *unused, double *out_19598108828665550);
void car_H_30(double *state, double *unused, double *out_498744389507002840);
void car_h_26(double *state, double *unused, double *out_5729013140666198620);
void car_H_26(double *state, double *unused, double *out_7289806023836875797);
void car_h_27(double *state, double *unused, double *out_5099985500443335526);
void car_H_27(double *state, double *unused, double *out_2673507701307427751);
void car_h_29(double *state, double *unused, double *out_8737435028697357876);
void car_H_29(double *state, double *unused, double *out_4386870428176978784);
void car_h_28(double *state, double *unused, double *out_2063199448999002841);
void car_H_28(double *state, double *unused, double *out_8977474628463042258);
void car_h_31(double *state, double *unused, double *out_3763371243646011771);
void car_H_31(double *state, double *unused, double *out_7384788769121659167);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}