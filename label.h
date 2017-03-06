
char const * fname[] = {
	"test/",			// 0
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_v5/170303_135919/0000/",			// 1 pPb HM0 standard
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_v5/170304_100734/0000/",			// 2 pPb HM1 standard
	"",			// 3 pPb HM2 standard
	"",			// 4 pPb HM3 standard
	"",			// 5 pPb HM4 standard
	"",			// 6 pPb HM5 standard
	"",			// 7 pPb HM6 standard
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_v5/170304_100748/0000/",			// 8 pPb HM7 standard
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_v5/170304_101121/0000/",				// 9 pPb MB1 standard
	"../pPb/PAMinimumBias2/crab_PAMB2_cumugap_eff_v4/170227_152727/0000/",				// 10 pPb MB2 standard
	"../pPb/PAMinimumBias3/crab_PAMB3_cumugap_eff_v4/170227_152748/0000/",				// 11 pPb MB3 standard
	"../pPb/PAMinimumBias4/crab_PAMB4_cumugap_eff_v4/170227_152827/0000/",				// 12 pPb MB4 standard
	"../pPb/PAMinimumBias5/crab_PAMB5_cumugap_eff_v4/170227_152848/0000/",				// 13 pPb MB5 standard
	"../pPb/PAMinimumBias6/crab_PAMB6_cumugap_eff_v4/170227_152904/0000/",				// 14 pPb MB6 standard
        "NA",			// 15 pPb MB sum standard
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumugap_eff_reverse_v5/170305_142853/0000/",		// 16 pPb HM0 reverse
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumugap_eff_reverse_v5/170305_142915/0000/",		// 17 pPb HM1 reverse
	"",			// 18 pPb HM2 reverse
	"",			// 19 pPb HM3 reverse
	"",			// 20 pPb HM4 reverse
	"",			// 21 pPb HM5 reverse
	"",			// 22 pPb HM6 reverse
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumugap_eff_reverse_v5/170305_142933/0000/",		// 23 pPb HM7 reverse
	"../pPb/PAMinimumBias1/crab_PAMB1_cumugap_eff_reverse_v5/170305_143849/0000/",			// 24 pPb MB1 reverse
	"",			// 25 pPb MB2 reverse
	"",			// 26 pPb MB3 reverse
	"",			// 27 pPb MB4 reverse
	"",			// 28 pPb MB5 reverse
	"",			// 29 pPb MB6 reverse
	"NA",		// 30 pPb MB sum reverse
	"../pPb/HighMultiplicity/crab_PPHM_totem_cumugap_eff_v1/170303_103746/0000/",			// 31 pp HM TOTEM
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_CumuGap_ppReco_eff_noff_v1/170303_115252/0000/",	// 32 PbPb 5 TeV pp reco
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
	"txt/PAMB_full/",		// 15
	"txt/PAHM0_reverse/",		// 16
	"txt/PAHM1_reverse/",		// 17
	"txt/PAHM2_reverse/",		// 18
	"txt/PAHM3_reverse/",		// 19
	"txt/PAHM4_reverse/",		// 20
	"txt/PAHM5_reverse/",		// 21
	"txt/PAHM6_reverse/",		// 22
	"txt/PAHM7_reverse/",		// 23
	"txt/PAMB1_reverse/",		// 24
	"txt/PAMB2_reverse/",		// 25
	"txt/PAMB3_reverse/",		// 26
	"txt/PAMB4_reverse/",		// 27
	"txt/PAMB5_reverse/",		// 28
	"txt/PAMB6_reverse/",		// 29
	"txt/PAMB_reverse_full/",	// 30
	"txt/PP15_TOTEM/",		// 31
	"txt/PbPb15_ppreco/",		// 32
};


#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumugap/trV", fname[s1]));
}
