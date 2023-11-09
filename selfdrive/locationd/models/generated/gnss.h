#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_2297846703375512046);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_111414451545151170);
void gnss_H_mod_fun(double *state, double *out_1712036253867640506);
void gnss_f_fun(double *state, double dt, double *out_2420600810694362224);
void gnss_F_fun(double *state, double dt, double *out_4114427183775962978);
void gnss_h_6(double *state, double *sat_pos, double *out_2949676141157986562);
void gnss_H_6(double *state, double *sat_pos, double *out_6630096978930967114);
void gnss_h_20(double *state, double *sat_pos, double *out_4956105181449293521);
void gnss_H_20(double *state, double *sat_pos, double *out_3156613020081298281);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2199945742104997938);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_5021442328268011661);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2199945742104997938);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_5021442328268011661);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}