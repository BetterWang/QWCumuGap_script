from ROOT import TFile, TGraphErrors, TH1D, TH1
from ROOT import gROOT
from array import array
import numpy as np


ffflist = [
        ['txt/Hydjet5-10_0/outGraph.root',  0],
        ['txt/Hydjet5-10_2/outGraph.root',  0],
        ['txt/Hydjet5-10_4/outGraph.root',  0],

        ['txt/Hydjet10-15_0/outGraph.root',  0],
        ['txt/Hydjet10-15_2/outGraph.root',  0],
        ['txt/Hydjet10-15_4/outGraph.root',  0],

        ['txt/Hydjet15-20_0/outGraph.root',  0],
        ['txt/Hydjet15-20_2/outGraph.root',  0],
        ['txt/Hydjet15-20_4/outGraph.root',  0],

        ['txt/Hydjet20-25_0/outGraph.root', 2],
        ['txt/Hydjet20-25_2/outGraph.root', 2],
        ['txt/Hydjet20-25_4/outGraph.root', 2],

        ['txt/Hydjet25-30_0/outGraph.root',  0],
        ['txt/Hydjet25-30_2/outGraph.root',  0],
        ['txt/Hydjet25-30_4/outGraph.root',  0],

        ['txt/Hydjet30-35_0/outGraph.root',  0],
        ['txt/Hydjet30-35_2/outGraph.root',  0],
        ['txt/Hydjet30-35_4/outGraph.root',  0],

        ['txt/Hydjet35-40_0/outGraph.root', 3],
        ['txt/Hydjet35-40_2/outGraph.root', 3],
        ['txt/Hydjet35-40_4/outGraph.root', 3],
        ]

fflist = [
        ['txt/HIJING_fEllP_8pct_v2_mod1/outGraph.root', 2],
        ['txt/HIJING_mod0//outGraph.root', 2],
        ]

flist = [
    'txt/PAHM0_sysTight2_merge/outputC_0_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_1_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_2_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_3_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_4_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_5_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_6_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_7_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_8_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_9_10.root',
    'txt/PAHM0_sysTight2_merge/outputC_10_10.root'
    ]

grlist = [ 'hV8nR2' ]

#for f in flist:
#    hfile = TFile(f[0])
#    gr = [ hfile.Get(x) for x in grlist ]
#    print('\n' + f[0])
#    for idx, g in enumerate(grlist):
#        print(g)
#        #print(gr[idx].GetY()[f[1]])
#        print(str(gr[idx].GetY()[f[1]]) + " +/- " + str(gr[idx].GetEY()[f[1]]))

ratio86 = [];
for f in flist:
    hfile = TFile(f);
    hist8 = hfile.Get('hV8nR2')
    hist6 = hfile.Get('hV6nR2')
    ratio86.append(hist8.GetBinContent(7) / hist6.GetBinContent(7));


r86 = np.array(ratio86[:10]) - ratio86[10]
print(ratio86)
print(r86)
print( (r86 * r86).sum() )
print( np.sqrt((r86 * r86).sum()) )

