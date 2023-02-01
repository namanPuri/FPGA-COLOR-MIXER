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
    work_m_00000000002219996280_3118688157_init();
    work_m_00000000001455558443_1001507631_init();
    work_m_00000000000278186113_0317111402_init();
    work_m_00000000000818333852_0301228443_init();
    work_m_00000000003348310534_2658763023_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000003348310534_2658763023");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
