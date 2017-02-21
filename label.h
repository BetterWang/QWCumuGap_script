
char const * fname[] = {
	"test/",			// 0
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_v3/170220_042427/0000/",			// 1 pPb HM0 standard
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_v3/170220_042439/0000/",			// 2 pPb HM1 standard
	"",			// 3 pPb HM2 standard
	"",			// 4 pPb HM3 standard
	"",			// 5 pPb HM4 standard
	"",			// 6 pPb HM5 standard
	"",			// 7 pPb HM6 standard
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_v3/170220_042451/0000/",			// 8 pPb HM7 standard
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_v3/170220_042255/0000/",				// 9 pPb MB1 standard
	"../pPb/PAMinimumBias2/crab_PAMB2_cumugap_eff_v3/170220_042306/0000/",				// 10 pPb MB1 standard
	"../pPb/PAMinimumBias3/crab_PAMB3_cumugap_eff_v3/170220_042321/0000/",				// 11 pPb MB1 standard
	"../pPb/PAMinimumBias4/crab_PAMB4_cumugap_eff_v3/170220_042334/0000/",				// 12 pPb MB1 standard
	"../pPb/PAMinimumBias5/crab_PAMB5_cumugap_eff_v3/170220_042346/0000/",				// 13 pPb MB1 standard
	"../pPb/PAMinimumBias6/crab_PAMB6_cumugap_eff_v3/170220_042359/0000/",				// 14 pPb MB1 standard
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
	"txt/PAMB2/",			// 10
	"txt/PAMB3/",			// 11
	"txt/PAMB4/",			// 12
	"txt/PAMB5/",			// 13
	"txt/PAMB6/",			// 14
};


#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumugap/trV", fname[s1]));
}
