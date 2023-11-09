#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_6966851622720554905);
void live_err_fun(double *nom_x, double *delta_x, double *out_1895595563132109511);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5918972879153741265);
void live_H_mod_fun(double *state, double *out_6876377137376417741);
void live_f_fun(double *state, double dt, double *out_5791094757475201);
void live_F_fun(double *state, double dt, double *out_1824726083210226094);
void live_h_4(double *state, double *unused, double *out_7744099854518732524);
void live_H_4(double *state, double *unused, double *out_6945900172785359080);
void live_h_9(double *state, double *unused, double *out_7785195367908494766);
void live_H_9(double *state, double *unused, double *out_341318762479088390);
void live_h_10(double *state, double *unused, double *out_1856656037786943409);
void live_H_10(double *state, double *unused, double *out_7201014775213551995);
void live_h_12(double *state, double *unused, double *out_2041121912589553409);
void live_H_12(double *state, double *unused, double *out_1926443764753397285);
void live_h_35(double *state, double *unused, double *out_479102439633132799);
void live_H_35(double *state, double *unused, double *out_819119267571616424);
void live_h_32(double *state, double *unused, double *out_4732705301287888481);
void live_H_32(double *state, double *unused, double *out_2759957604904625225);
void live_h_13(double *state, double *unused, double *out_4357223883178351739);
void live_H_13(double *state, double *unused, double *out_1257442621552807385);
void live_h_14(double *state, double *unused, double *out_7785195367908494766);
void live_H_14(double *state, double *unused, double *out_341318762479088390);
void live_h_33(double *state, double *unused, double *out_7459140836311137657);
void live_H_33(double *state, double *unused, double *out_3969676272210474028);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}