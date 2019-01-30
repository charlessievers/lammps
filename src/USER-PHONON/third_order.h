//
// Created by charlie sievers on 7/5/18.
//


#ifdef COMMAND_CLASS

CommandStyle(third_order,ThirdOrder)

#else

#ifndef LMP_THIRD_ORDER_H
#define LMP_THIRD_ORDER_H

#include "pointers.h"

namespace LAMMPS_NS {

    class ThirdOrder : protected Pointers {
    public:
        ThirdOrder(class LAMMPS *);
        virtual ~ThirdOrder();
        void command(int, char **);
        void setup();

    protected:
        int eflag,vflag;            // flags for energy/virial computation
        int external_force_clear;   // clear forces locally or externally


        int triclinic;              // 0 if domain is orthog, 1 if triclinic
        int pairflag;

        int pair_compute_flag;            // 0 if pair->compute is skipped
        int kspace_compute_flag;          // 0 if kspace->compute is skipped

        int nvec;                   // local atomic dof = length of xvec

        void energy_force(int);
        void force_clear();
        virtual void openfile(const char* filename);


    private:
        void options(int, char **);
        void calculateMatrix(char *arg);
        void convert_units(const char *style);

        double conversion;
        double conv_energy;
        double conv_distance;
        double conv_mass;
        int igroup,groupbit;
        int scaleflag;
        int me;

        int compressed;            // 1 if dump file is written compressed, 0 no
        int binaryflag;            // 1 if dump file is written binary, 0 no
        int file_opened;           // 1 if openfile method has been called, 0 no
        int file_flag;             // 1 custom file name, 0 dynmat.dat

        FILE *fp;
    };
}


#endif //LMP_THIRD_ORDER_H
#endif
