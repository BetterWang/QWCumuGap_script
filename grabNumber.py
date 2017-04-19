from ROOT import TFile, TGraphErrors
from ROOT import gROOT
from array import array


flist = [
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

grlist = [ 'grV42', 'grV62', 'grV82' ]

for f in flist:
    hfile = TFile(f[0])
    gr = [ hfile.Get(x) for x in grlist ]
    print('\n' + f[0])
    for idx, g in enumerate(grlist):
        print(g)
        #print(gr[idx].GetY()[f[1]])
        print(str(gr[idx].GetY()[f[1]]) + " +/- " + str(gr[idx].GetEY()[f[1]]))
