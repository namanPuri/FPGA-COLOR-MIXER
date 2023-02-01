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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000000749369418_0450250084_init();
    work_m_00000000001069409211_4196211228_init();
    work_m_00000000002993104608_2770294520_init();
    work_m_00000000002618979330_1323274903_init();
    work_m_00000000001012137261_3306708044_init();
    work_m_00000000003709530348_0273249354_init();
    work_m_00000000001373504721_2346200507_init();
    work_m_00000000004163449049_3846602194_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000004163449049_3846602194");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
