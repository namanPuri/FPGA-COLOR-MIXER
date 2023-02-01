/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "F:/CEDT projects/color_mixer_fpga/codes/uart_rx/uart_rx_tb.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {15U, 0U};
static unsigned int ng4[] = {143U, 0U};
static unsigned int ng5[] = {26U, 0U};
static unsigned int ng6[] = {154U, 0U};
static unsigned int ng7[] = {47U, 0U};
static unsigned int ng8[] = {175U, 0U};
static unsigned int ng9[] = {54U, 0U};
static unsigned int ng10[] = {182U, 0U};



static int sp_transmit_uart(char *t1, char *t2)
{
    char t9[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(63, ng0);

LAB5:    xsi_set_current_line(64, ng0);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    xsi_process_wait(t6, 200000LL);
    *((char **)t3) = &&LAB6;
    t0 = 1;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(65, ng0);
    t7 = ((char*)((ng1)));
    t8 = (t1 + 2520);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 1);
    xsi_set_current_line(66, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB7;
    t0 = 1;
    goto LAB1;

LAB7:    xsi_set_current_line(66, ng0);
    t6 = (t1 + 2840);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 0);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t18 = (t1 + 2520);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(67, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB8;
    t0 = 1;
    goto LAB1;

LAB8:    xsi_set_current_line(67, ng0);
    t6 = (t1 + 2840);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 1);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 1);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t18 = (t1 + 2520);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB9;
    t0 = 1;
    goto LAB1;

LAB9:    xsi_set_current_line(68, ng0);
    t6 = (t1 + 2840);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 2);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 2);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t18 = (t1 + 2520);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB10;
    t0 = 1;
    goto LAB1;

LAB10:    xsi_set_current_line(69, ng0);
    t6 = (t1 + 2840);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 3);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 3);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t18 = (t1 + 2520);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(70, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB11;
    t0 = 1;
    goto LAB1;

LAB11:    xsi_set_current_line(70, ng0);
    t6 = (t1 + 2840);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 4);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 4);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t18 = (t1 + 2520);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB12;
    t0 = 1;
    goto LAB1;

LAB12:    xsi_set_current_line(71, ng0);
    t6 = (t1 + 2840);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 5);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 5);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t18 = (t1 + 2520);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(72, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB13;
    t0 = 1;
    goto LAB1;

LAB13:    xsi_set_current_line(72, ng0);
    t6 = (t1 + 2840);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 6);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 6);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t18 = (t1 + 2520);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(73, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB14;
    t0 = 1;
    goto LAB1;

LAB14:    xsi_set_current_line(73, ng0);
    t6 = (t1 + 2840);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t11 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 7);
    t14 = (t13 & 1);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t11);
    t16 = (t15 >> 7);
    t17 = (t16 & 1);
    *((unsigned int *)t10) = t17;
    t18 = (t1 + 2520);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 1);
    xsi_set_current_line(74, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB15;
    t0 = 1;
    goto LAB1;

LAB15:    xsi_set_current_line(74, ng0);
    t6 = ((char*)((ng2)));
    t7 = (t1 + 2520);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 833300000LL);
    *((char **)t3) = &&LAB16;
    t0 = 1;
    goto LAB1;

LAB16:    goto LAB4;

}

static void Initial_46_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(46, ng0);

LAB2:    xsi_set_current_line(48, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 2360);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(49, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 2520);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(50, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2680);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_57_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 4008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 3816);
    xsi_process_wait(t2, 50000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(57, ng0);
    t4 = (t0 + 2680);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 2680);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_79_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 4256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(79, ng0);

LAB4:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4064);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 2840);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 8);

LAB7:    t7 = (t0 + 4160);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB9:    if (t15 != 0)
        goto LAB10;

LAB5:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB6:    t16 = (t0 + 4160);
    t17 = *((char **)t16);
    t16 = (t0 + 848);
    t18 = (t0 + 4064);
    t19 = 0;
    xsi_delete_subprogram_invocation(t16, t17, t0, t18, t19);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4064);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 2840);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 8);

LAB13:    t7 = (t0 + 4160);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB15:    if (t15 != 0)
        goto LAB16;

LAB11:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB12:    t16 = (t0 + 4160);
    t17 = *((char **)t16);
    t16 = (t0 + 848);
    t18 = (t0 + 4064);
    t19 = 0;
    xsi_delete_subprogram_invocation(t16, t17, t0, t18, t19);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4064);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 2840);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 8);

LAB19:    t7 = (t0 + 4160);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB21:    if (t15 != 0)
        goto LAB22;

LAB17:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB18:    t16 = (t0 + 4160);
    t17 = *((char **)t16);
    t16 = (t0 + 848);
    t18 = (t0 + 4064);
    t19 = 0;
    xsi_delete_subprogram_invocation(t16, t17, t0, t18, t19);
    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 4064);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 2840);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 8);

LAB25:    t7 = (t0 + 4160);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB27:    if (t15 != 0)
        goto LAB28;

LAB23:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB24:    t16 = (t0 + 4160);
    t17 = *((char **)t16);
    t16 = (t0 + 848);
    t18 = (t0 + 4064);
    t19 = 0;
    xsi_delete_subprogram_invocation(t16, t17, t0, t18, t19);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 4064);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 2840);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 8);

LAB31:    t7 = (t0 + 4160);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB33:    if (t15 != 0)
        goto LAB34;

LAB29:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB30:    t16 = (t0 + 4160);
    t17 = *((char **)t16);
    t16 = (t0 + 848);
    t18 = (t0 + 4064);
    t19 = 0;
    xsi_delete_subprogram_invocation(t16, t17, t0, t18, t19);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 4064);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 2840);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 8);

LAB37:    t7 = (t0 + 4160);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB39:    if (t15 != 0)
        goto LAB40;

LAB35:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB36:    t16 = (t0 + 4160);
    t17 = *((char **)t16);
    t16 = (t0 + 848);
    t18 = (t0 + 4064);
    t19 = 0;
    xsi_delete_subprogram_invocation(t16, t17, t0, t18, t19);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 4064);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 2840);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 8);

LAB43:    t7 = (t0 + 4160);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB45:    if (t15 != 0)
        goto LAB46;

LAB41:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB42:    t16 = (t0 + 4160);
    t17 = *((char **)t16);
    t16 = (t0 + 848);
    t18 = (t0 + 4064);
    t19 = 0;
    xsi_delete_subprogram_invocation(t16, t17, t0, t18, t19);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 4064);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 2840);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 8);

LAB49:    t7 = (t0 + 4160);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB51:    if (t15 != 0)
        goto LAB52;

LAB47:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB48:    t16 = (t0 + 4160);
    t17 = *((char **)t16);
    t16 = (t0 + 848);
    t18 = (t0 + 4064);
    t19 = 0;
    xsi_delete_subprogram_invocation(t16, t17, t0, t18, t19);

LAB1:    return;
LAB8:;
LAB10:    t7 = (t0 + 4256U);
    *((char **)t7) = &&LAB7;
    goto LAB1;

LAB14:;
LAB16:    t7 = (t0 + 4256U);
    *((char **)t7) = &&LAB13;
    goto LAB1;

LAB20:;
LAB22:    t7 = (t0 + 4256U);
    *((char **)t7) = &&LAB19;
    goto LAB1;

LAB26:;
LAB28:    t7 = (t0 + 4256U);
    *((char **)t7) = &&LAB25;
    goto LAB1;

LAB32:;
LAB34:    t7 = (t0 + 4256U);
    *((char **)t7) = &&LAB31;
    goto LAB1;

LAB38:;
LAB40:    t7 = (t0 + 4256U);
    *((char **)t7) = &&LAB37;
    goto LAB1;

LAB44:;
LAB46:    t7 = (t0 + 4256U);
    *((char **)t7) = &&LAB43;
    goto LAB1;

LAB50:;
LAB52:    t7 = (t0 + 4256U);
    *((char **)t7) = &&LAB49;
    goto LAB1;

}


extern void work_m_00000000004163449049_3846602194_init()
{
	static char *pe[] = {(void *)Initial_46_0,(void *)Always_57_1,(void *)Initial_79_2};
	static char *se[] = {(void *)sp_transmit_uart};
	xsi_register_didat("work_m_00000000004163449049_3846602194", "isim/uart_rx_tb_isim_beh.exe.sim/work/m_00000000004163449049_3846602194.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
