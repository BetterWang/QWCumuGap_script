
char const * fname[] = {
	"test/",			// 0
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_v1/170215_180405/0000/",			// 1 pPb HM0 standard
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_v1/170215_180420/0000/",			// 2 pPb HM1 standard
	"",			// 3 pPb HM2 standard
	"",			// 4 pPb HM3 standard
	"",			// 5 pPb HM4 standard
	"",			// 6 pPb HM5 standard
	"",			// 7 pPb HM6 standard
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_v1/170215_180432/0000/",			// 8 pPb HM7 standard
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_v1/170219_072350/0000/",				// 9 pPb MB1 standard
};

char const * ftxt[] = {
	"txt/test/",			// 0
	"txt/PAHM0/",			// 1
	"txt/PAHM1/",			// 2
	"txt/PAHM2/",			// 3
	"txt/PAHM3/",			// 4
	"txt/PAHM4/",			// 5
	"txt/PAHM5/",			// 6
	"txt/PAHM6/",			// 7
	"txt/PAHM7/",			// 8
	"txt/PAMB1/",			// 9
};


#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumugap/trV", fname[s1]));
}
