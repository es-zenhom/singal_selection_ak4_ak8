#include <iostream>
#include <TH1D.h>
#include <vector>
#include <TMath.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>
#include <Math/Vector4D.h>
#include <Math/GenVector/PtEtaPhiM4D.h>
#include <TString.h>
#include <Math/VectorUtil.h>
#include <TH2D.h>
#include "TChain.h"
#include <string>
#include "TString.h"
#include "Nano.h"







//  for tjhe background enEventCount   = 1320000
//nt.genEventSumw()    = 4.14463e+08
//for the signal



int main(int argc, const char* argv[])
{

    using namespace std;
    std::vector<TString> input_files;


    if (argc < 2)
    {
        std::cout << "Error! you must provide a valid argument!"<<std::endl;
        std::cout << "help:" << std::endl;
        std::cout << "" << std::endl;
        std::cout << " e.g." << std::endl;
        std::cout << "    $ " << argv[0] << " " << "signal_zzh" << std::endl;
        std::cout << "    $ " << argv[0] << " " << "signal_wzh" << std::endl;
        std::cout << "    $ " << argv[0] << " " << "signal_wwh" << std::endl;
        std::cout << "    $ " << argv[0] << " " << "signal_oswwh" << std::endl;
        std::cout << "    $ " << argv[0] << " " << "background" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "  User must run the program with one of the above" << std::endl;
        return 1;
    }
    if (argc >2)
    {
        cout << "Error! enter only 2 arguments"<<endl;
        return 2;
    }




    std::string sample_type1 = argv[1];



    TFile * f_output;
    TChain * chain1;
    float cross_section=0;
    // read file and TTree

    if (sample_type1=="background")
    {

        //nt.SetYear(2018);

        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/0257FF80-DD8C-BB48-B036-B10F8CCF064D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/034EAF20-99D4-2149-BE72-56068A856641.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/05843D24-DAB6-CC4C-BB2B-863C8E57D98D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/05EC72E6-802E-5F4B-B53D-A9BB981239F8.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/06DB2DFB-69F2-444A-BFC4-8EF3B541CFDA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/07AACC17-1358-E54E-AA5F-6FCE7D5C9C3F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/082C1905-47BF-4C49-8140-9EF6DC84311F.root ");
        //input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/0880B388-BCEE-CE48-B449-88DC67AE7D32.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/09228E76-1066-2547-9C2E-2B23BB9F3DB5.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/0A0C246F-D01B-6F4D-85E6-3A75C27C5197.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/0BA4FF11-0A8E-D745-8517-3F1602AFADB8.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/0DC0F062-1B11-6343-AB06-709CE2A42CD6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/100C63EF-8913-804F-B84E-3BF28DFAEC2A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/1011D672-20E7-1D45-976D-33DE44D8DDD1.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/11AF38E2-B027-8747-9CC4-C3527495602A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/1255A5E0-2B89-BA47-9E2B-2A7BA24A15EC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/126D6C81-2140-BC47-824C-D7F575C35A1B.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/13153750-6827-264D-AF5B-FF184000E0F0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/131C6DC0-D533-1040-A95C-A32E17C9613D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/170F5D27-2BF7-4244-8820-9B3B3158C9EA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/17BC4535-0FE0-B249-ABD3-DB1DEFE3182C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/18513E87-5FD6-6C4D-8F3E-EDA5939A381E.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/188430F4-81C9-494B-993E-05D46DBAB686.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/18D885EA-36C9-5A4C-A686-449C956DD035.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/1AB98F8E-9E82-8E43-9AD6-6E376326AF72.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/1B6E5EEB-B1E1-D643-AF3F-09D4FE3F4306.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/1BF343BC-A259-FA47-BA26-FEF6B0C30D61.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/1C7E486F-3952-FD4F-A152-597BE0AEB594.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/1CD65D5C-5438-E049-BE5A-2C3CDC11C6CA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/1DC21889-9132-A041-9BAF-BFFB4ACC745C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/21EB1750-71F2-8844-A247-B6C6BACE63DB.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/23929225-F620-C347-93C1-38196F9EF323.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/24E872C2-B6FD-2B4D-94CA-6955B636AF0F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/250244B9-822D-DE47-A2E8-FFD6C10C0A55.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/25B468C6-5DA4-2E46-A639-292927E3A705.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/261FB251-5D3E-1943-A462-61A77C38E97A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/26A15F96-3D78-2F41-9258-E74A54C9CF61.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/281BA13D-A04D-274F-83C1-A6A0F735EE7C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/2943BADE-0A71-2446-BE8F-B326A07060E9.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/2A55A6C5-A48F-F14E-AE3A-01E23205E7B0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/2DABA311-40FC-F047-9591-E1217DDC72FB.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/2E0DC00F-59C6-394D-80A4-DBAF7607521F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/2E22AA7A-3001-F64F-9B50-BD38C493A6FA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/2FDCB103-08AA-6546-ADE9-EAAB6E720D97.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/303D14F2-F472-D34C-AB77-DE036457D26D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/318D91C1-DB96-114A-BA08-C3EB241E44AC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/326D2A86-618C-044D-959B-245444243764.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/327E6857-E387-7F43-A607-51BAD8096C59.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/33A96479-9062-7442-A413-C9B72CA7E22A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/342CE214-EBE2-324D-B2F9-0766A04C1E72.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/348F8FFD-BE1F-BC4E-9804-D234D661B10F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/34C80B24-02B4-684B-BF94-59FAC0001D10.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/354C4AF0-4EC5-A64D-9BFB-8577DD55B176.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/3605AFA3-8488-D540-9DDF-07B365ECBCA1.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/392B92C9-E962-804E-B348-A6EFB711492F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/39E2A7A4-6A6B-724A-B4E3-04CB705FEFC9.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/3A4CD9A0-57A2-9F4F-987F-C5026387FB9C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/3AD00AE0-CCF0-C540-93BE-48158B9A00FA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/3E43D901-0E6F-444E-BD11-469CFFE7B06E.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/3F0E248E-FB10-4F4B-BCE2-190EF4B01CDE.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/3F5773D7-04DC-5441-94EE-E7519C7A17BF.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/40AE2766-5D6C-464E-8AE7-388A2738E7DF.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/40F33D96-D388-E441-9BA5-56F7CE861288.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/43705823-8B38-C44F-AE84-404EF326216B.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/45C3A27F-0403-1D44-ACBC-8DAF21B383CD.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/45D2FBC0-AACA-CE4C-8E13-E03252353F4C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/4835B638-9592-E04C-A421-6D0EF226C94E.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/487E04A9-8D27-5640-AF60-674996ED4FFC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/4971F5D6-CA6C-DF4C-BC0F-855061288676.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/4B1FE4E6-CA8E-AB47-AF42-59857249E10A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/4B858AEA-4271-A844-AC49-A2F3D3F8FAAE.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/4C22DA7D-DA18-9849-B816-0D6281CBC5DD.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/519895C6-E7BF-1144-BC1F-740677310BFC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/51BE8576-A262-9848-B80A-B6D2812392C5.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/5412D2EC-6610-4A43-AAB2-1B03823C0926.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/554611E7-4E1E-1F4E-B6ED-7481E5E715F2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/5592BA84-283F-CB46-AC52-DF81B1FE09DA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/5622D198-C3B3-4645-83C1-69F1529BF51A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/57079AB2-6B36-B341-AF1F-F227BD19324F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/5CC83212-6974-C241-841A-B52CA16B05EA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/5EB0F6DC-128D-604D-BA2D-E7AE902933A1.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/5FAF39B4-898B-BD4A-BB3C-CF0E39604D8E.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/5FE2C578-1587-9647-A11B-F2D70291333F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/60E3F4D1-D30D-AC46-AD95-07C372B2F2BD.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/6268F1B6-02A9-834F-90E1-8364B742301C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/62F024E1-14CC-2E48-B215-A12E95FE16C6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/676011B6-B869-C343-B164-A678027F9397.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/698E2246-AD8E-BC44-9916-764881374173.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/6A24C018-64A6-DA4D-9FCD-F9ADEA1E56BB.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/6A3C09C3-967F-F04A-A380-8996B33CBB8C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/6A6B386E-2C87-B24F-B670-B41F226E3E03.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/6AD3388F-257B-B94A-BBD9-80ABEAD4F75D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/6D030410-1785-8E46-B383-D8632A04C3A1.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/6EABFF4D-A531-4342-874F-9A03916C3E19.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/6FE917A3-6881-324F-B62B-DDF109EF85EC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/704B02C2-D9B4-C543-B454-14ED3D7DF3A3.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/725EF4C5-0061-1941-B616-869E1C920F92.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/731F22BC-EBF2-BD40-8D7D-9A71172D6DCE.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7406D513-CA1D-794A-BF39-4CC564949E3C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7437E603-2CE5-0D42-8D37-248C42899FB8.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/74506901-5FCF-2A4B-AE53-D30EF7D879A1.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/74A3F723-51D9-C748-9FDD-2D7A40B929B7.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7639D289-0C9D-C84D-89BF-46593C3C9AA4.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/767693FE-B81A-9243-A7AC-C37797E0F7E2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/76C55FEB-FD73-EB45-B5FF-E73C052046D6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/76EB5D6D-4BD3-9A43-B56E-4DBBC251B6B8.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/78F0235E-D690-9644-86EA-DF4156ED89D2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/79436AC9-B661-CA44-9A3E-1970A323C3AF.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/796DEDAD-1E38-FF4F-A35E-1E90F6F02AD7.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7A3185F8-CD66-0941-A025-1E35370C37C0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7A7F88B7-E341-1340-BB6F-52D01A29614D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7CB75917-7C9E-344D-B7EF-7D619BAA066A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7D3D057B-DD50-DC40-B04A-E68E028441BC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7D5FC7C5-2C60-DD40-9070-7015C59E2C67.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7DDEBF3F-23D8-C542-8990-1A01786317AC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/7F883502-6B69-9242-8C5D-1A0AF446B18B.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/80BF0CB3-05BE-A14A-A9A6-F54A63190138.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/81ECEA2D-67E5-BB46-AA42-375F7C9E30AB.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/85566B74-5FDE-234B-A9FF-D47043550EE7.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/8559502A-7D1C-6945-AF22-956D50EC6298.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/85850AD3-7907-024A-AE29-C23B9483981D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/86791F6E-F7D7-874F-9534-F81730273384.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/874A09BC-9725-E846-965E-4D45EEC59C6F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/87E7DCC5-C974-AD45-9BD0-CB6878BCB4AB.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/8C730B50-AF62-9148-81EE-AD7258460C29.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/8D7113CF-C3CE-9948-BAE5-7CE6035301B3.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/8DDD0BD8-596D-DA4A-A64C-935980240C7A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/8E09AF83-2520-CF42-AC90-084A361FFC2F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/90988D3D-4E69-4346-9B5B-8CC95A387045.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/93480B35-0DAB-364E-ACE2-EABF8C0A1F9A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/93AA745C-D894-CA43-8BD7-F5FA90020F2B.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/9661A075-2BF5-7644-A438-0DE0991048CD.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/973A56D0-FA4B-6A45-9767-302571AF419C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/981CFCFA-E72E-CB42-9324-560DDFC0CE50.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/98C1D69E-BA2A-6746-8613-CBCC88F4CFB6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/99844F43-0CCF-284C-B3BF-DBBDFC8DF2F2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/999CD782-0E4E-1E4D-8C0F-C57F2766F330.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/99C978CC-4DAF-D44A-9726-E6C793FF1783.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/99F64F2B-DCDF-C941-AB89-9FB1F397AA60.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/9A4769BD-1AE6-F748-AEF5-DE74CE440FC6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/9D186BF0-5601-5C46-A6C7-8749F4E6FB5A.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/9D76699A-55F7-2241-B876-EF815D55476D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/9DDF4B7B-2314-D44D-808C-47A1337EC3F6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/9F3D11CA-265C-1346-8087-AFE8C32F4B77.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/A1CCAD6E-1886-CA45-B8B6-5AF676F725D2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/A216BD4F-C4EE-1E43-A060-A72E6B55FDA5.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/A35233A4-3DE3-9E40-91F8-E7A6E6E5C238.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/A4F3DB50-C1A6-5042-B070-DC1AAD727E9E.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/ACA88AC3-9163-564E-BE25-ED7705AEEBD0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/ADF7B1A5-87CB-A440-BAFE-530C566E442C.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/AEBC47B3-AF59-C441-8EF5-23D5A266C967.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/AF72BD8E-DEBB-464D-9C2B-477EC3C3F3A8.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/AF730D6D-A62C-BF48-B022-E77350D8A044.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B04F0950-A624-CD42-A517-A6D7DD416FC5.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B0A7D711-8E87-8547-A044-829722F446DC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B50D44BA-B035-EE46-812C-3127696B1BF9.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B525C90B-1A2B-894B-8911-B7F2AAE4738E.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B6A56CCA-CA78-3345-8015-CA332E51B272.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B740FF92-5ADF-1D46-B9C1-62600705B719.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B77296B8-15C9-D346-B814-623C48113788.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B8CE603C-F63D-B840-AD6E-94124383E455.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B93C7329-144F-334B-9DD3-B0156818C7D7.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/B9C3DB1C-5BEC-5A44-B3EA-A5A73BC000C0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/BB2FC418-CA90-E44D-8D1E-6F90AA978FCC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/BCF2A7F2-1DCD-A741-9367-0E19C3040F96.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/BFF811BC-B080-2544-80E0-1CE625846ED6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C0187511-F2A4-C64F-A103-BE3C8684A4D5.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C0873D31-4668-5A43-B0F7-8603AAAE0914.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C33AF1BE-6013-7A45-B050-F6DED1CF1CFD.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C403E8C6-65F1-9C42-9332-EADB7B20AB0F.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C501DDAA-E356-EE44-8C30-2AA252F56EDB.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C5107248-AC2E-F44E-ADB7-01172E44825B.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C616DDFD-A758-6C4E-8254-2E252ECC1647.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C70B61C4-8C42-F047-AE56-FD3198089D73.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C822F38E-CD7A-A24E-A98A-6339A1A55B71.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C845B4CE-F5E5-2C49-9F3D-16A5BB9B3772.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C856AE41-F058-5244-A484-845D9A2BE552.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C88DE9DD-88D7-B84B-8DD9-3A53EE87DACF.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C985CE61-8873-3144-82E3-E74A35394E28.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C9AE400A-46AB-4245-B122-B545D4044D85.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/C9C4C7A4-4FDF-244B-A0B7-C9E9686954C0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/CA321822-F3FC-7242-B435-5956404CC787.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/CA6ED8C3-24CD-3D42-AEFC-DB54CEC1725D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/CAAD8C91-2CBA-1542-8A3D-D7FD4C2DCCEA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/CB7BE363-AF0C-294B-B5FD-58B2CBA47510.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/CE648103-4385-9844-A76A-AB7B18BFF1A0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/CEC22472-C5DD-B546-BF38-DAA7F5B74A13.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/CEFA132E-81E5-7348-8F5B-937EB1890913.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D0BEDC66-232A-0A46-A997-27D752684B69.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D0C2C906-F88D-144B-B9BE-1B26F76219A5.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D3A42F6A-D7E2-014B-AA58-649709D69750.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D432108A-749B-C44D-AFB8-DD23A0B2007E.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D4345960-08EE-0646-BE14-505C2B87CB7D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D69DC737-FF4A-F841-8720-C36739B09AD0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D6DDCAD1-FC7D-E741-AF79-B0D1653AE8A2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D74CE3FD-C498-9941-8E16-EAB57A4140D4.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D8290D19-DFBD-C34D-AFBC-83DF0CF38459.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D8C8BEE3-9E72-7A40-8E13-E56B29DA6B52.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/D9F29379-1142-514E-825F-B933CA0BCE1E.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/DAC0B68A-FA6E-434F-8CBD-27DE0A3E8453.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/DC87468E-E149-2848-92D3-5903F78BB2B4.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/DD6F0723-C18F-5B42-AB0C-A368392597BC.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/DF752D72-FADF-BC49-9835-921C0F011195.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E18EAB0D-60E5-E54A-A79D-004EB1938ED6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E1917910-26E0-7649-952B-192903B7532D.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E22ADDAE-9EB3-4746-A26F-AB2EE45CE334.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E2A162D0-EE44-EA4E-AB1F-91AD895845AF.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E2CE89AD-4FE5-7D4D-80D9-07E8F763F49B.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E359A687-2C4C-E644-84AE-6BF2B18C6D75.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E406141B-8A58-AF46-B849-B39A2B6C8B70.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E41FD753-74E1-DA43-B0C3-020EBB315153.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E5CC07A4-0F4E-7247-A6A7-F02210C26916.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E62515F3-0A51-B343-9A05-385884E5A134.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E6988611-0F7A-7149-BCA9-10FA600037D2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E6EE03D7-5EC1-9D4D-9E41-605619ADD3C2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E7865000-ACA4-F446-967F-E66E94FB31E3.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/E9F4249D-9832-9145-A059-C6BCF06556FF.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/EC4B1DE4-AC93-F940-86FC-3FCBE67B86B7.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/EDE546AE-39F3-8A46-9F0C-1B1D50603169.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/EE1F098C-B41F-6445-ADDA-4DD070D8C7A2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/EE60F92C-85D8-B84F-92F9-4348FC32C040.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/EFE4F59F-1545-5D48-B686-C2542C071276.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/F43C2AF4-8C6E-3C45-9FA2-51A8DF972BC2.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/F617BDA4-88EE-3246-8BAA-A4E321AE27C7.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/F713A26A-25B5-AF4E-A265-F54E313F0EDA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/F7931B4D-CDED-4F4B-A425-FA980A99D682.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/F853BDB2-1BCC-8E48-ADDB-6985FCEF4D73.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/F8D47067-95F4-F24B-A1ED-1689254FBAF6.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/F8E84B8D-DB29-134B-97C3-B6F8D9260B92.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/F8F59A96-165B-8744-A678-D5BA94572269.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/FA19A3A1-CCC0-2543-8E1F-957FD1E025D0.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/FBD34F7A-15F4-EA4C-9E6D-6788E4AA12CB.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/FC0A5437-B9D1-DC40-8D1C-0B3F30F11EBE.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/FC3E289F-60A5-1445-BFED-6CD8C526EEA5.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/FC5BA4AD-171A-6940-B404-EC6B0AC19544.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/FE3C14D8-4544-6F45-9F1F-EE700DECE8CA.root ");
        input_files.push_back("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/FF7BDF68-CC0A-174A-8362-6A137D1DDFB8.root ");



        f_output =new TFile ("background.root","recreate");
        cross_section=687.1;
        chain1 = new TChain("Runs");
        //chain1->Add("/home/users/eslam.zenhom/public_html/uf_work/VBSZZH/E6EE03D7-5EC1-9D4D-9E41-605619ADD3C2.root");
        chain1->Add("/ceph/cms/store/user/phchang/nanoaod/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/270000/*.root");
    }
    if (sample_type1=="signal_zzh")
    {

        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_0.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_10.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_11.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_12.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_13.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_14.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_15.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_16.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_17.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_1.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_2.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_3.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_4.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_5.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_6.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_7.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_8.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/merged_9.root");
        f_output =new TFile ("sig_VBSZZH.root","recreate");
        chain1 = new TChain("Runs");
        chain1->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSZZH_incl_C2V_0_Azure_v1/merged/*.root");
        cross_section=0.0008036;

    }
    if (sample_type1=="signal_oswwh")
    {

        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_0.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_1.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_10.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_11.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_12.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_13.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_14.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_15.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_16.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_17.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_2.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_3.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_4.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_5.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_6.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_7.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_8.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/merged_9.root");

        f_output =new TFile ("sig_VBSOSWWH.root","recreate");
        chain1 = new TChain("Runs");
        chain1->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSOSWWH_incl_C2V_0_Azure_v1/merged/*.root");
        cross_section=0.001747;

    }
    if (sample_type1=="signal_wwh")
    {

        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_0.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_1.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_10.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_11.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_12.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_13.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_14.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_15.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_16.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_17.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_2.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_3.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_4.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_5.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_6.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_7.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_8.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/merged_9.root");

        f_output =new TFile ("sig_VBSWWH.root","recreate");
        chain1 = new TChain("Runs");
        chain1->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/*.root");
        cross_section=0.001037;

    }
    if (sample_type1=="signal_wzh")
    {

        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_0.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_1.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_10.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_11.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_12.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_13.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_14.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_15.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_16.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_17.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_2.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_4.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_5.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_6.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_7.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_8.root");
        input_files.push_back("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/merged_9.root");

        f_output =new TFile ("sig_VBSWZH.root","recreate");
        chain1 = new TChain("Runs");
        chain1->Add("/ceph/cms/store/user/phchang/VBSVVHSignalSamples_v2/RunIISummer20UL18_VBSWZH_incl_C2V_0_Azure_v1/merged/*.root");
        cross_section=0.001169;

    }


    // initatie the variables



    // singal selection
    std::vector<ROOT::Math::PtEtaPhiMVector> ak4_pt_eta_cut {};
    std::vector<ROOT::Math::PtEtaPhiMVector> ak8_pt_msoftdrop_cut_4d {};
    std::vector<ROOT::Math::PtEtaPhiMVector> ak4_pt_eta_cut_overlap_4d {};
    //std::vector<ROOT::Math::PtEtaPhiMVector> ak8_pt_msoftdrop_cut_4d_overlab {};
    std::vector<float> marker{};
    // std::vector<float> inariant_mass_compare{};
    // std::vector<std::vector<int>> inariant_mass_compare_index_2d{};

    std::vector<float>   vec_H_score{};

    std::vector<ROOT::Math::PtEtaPhiMVector> vec_lead_sublead_bosons_4d {};

    std::vector<float>   vec_msoftdrop_two_bosons{};
    std::vector<float>   vec_msoftdrop{};

    std::vector<float>   vec_V_score{};
    std::vector<float>   vec_btag_score{};
    std::vector<ROOT::Math::PtEtaPhiMVector> vec_btag_4d {};


    std::vector<float>   vec_WvsQCD_score{};
    std::vector<float>   vec_ZvsQCD_score{};
    std::vector<float>   vec_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_XCD_score{};
    std::vector<float>   vec_Vboson_WvsQCD_score{};
    std::vector<float>   vec_Vboson_ZvsQCD_score{};
    std::vector<float>   vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score{};

    //  using the Max-E scheme
    std::vector<float>   vec_lead_sublead_vbfquarks_positive_eta{};
    std::vector<int>   vec_lead_sublead_vbfquarks_positive_eta_index{};
    std::vector<float>   vec_lead_sublead_vbfquarks_negative_eta{};
    std::vector<int>   vec_lead_sublead_vbfquarks_negative_eta_index{};

    // take the other two vv bosons to be the ones with the highest pt after we exclude the highest xbb score from the fat jets to be the higgs
    std::vector<float>   vec_lead_sublead_bosons_pt_tocompare{};





    // create the histograms
    TH1D* hist_pt_leadVBFQuark = new TH1D ("hist_pt_leadVBFQuark", "pT of leading VBFquark", 80,0,250);
    TH1D* hist_pt_subleadVBFQuark = new TH1D ("hist_pt_subleadVBFQuark", "pT of subleading VBFquark", 80,0,160);
    TH1D* hist_eta_leadVBFQuark = new TH1D ("hist_eta_leadVBFQuark", "eta of leading VBFquark", 80,-6,6);
    TH1D* hist_eta_subleadVBFQuark = new TH1D ("hist_eta_subleadVBFQuark", "eta of subleading VBFquark", 80,-6,6);
    TH1D* hist_phi_leadVBFQuark = new TH1D ("hist_phi_leadVBFQuark", "phi of leading VBFquark", 80,-6,6);
    TH1D* hist_phi_subleadVBFQuark = new TH1D ("hist_phi_subleadVBFQuark", "phi of subleading VBFquark", 80,-6,6);

    TH1D* hist_pt_H_fatjet = new TH1D ("hist_pt_H_fatjet", "pT of Higgs", 80,0,1800);
    TH1D* hist_eta_H_fatjet = new TH1D ("hist_eta_H_fatjet", "eta of Higgs", 80,-6,6);
    TH1D* hist_phi_H_fatjet = new TH1D ("hist_phi_H_fatjet", "phi of Higgs", 80,-6,6);
    TH1D* hist_m_H_msoftdrop = new TH1D ("hist_m_H_msoftdrop"," msoftdrop of H (mass)", 80,0,150);

    TH1D* hist_pt_leadboson_fatjet = new TH1D ("hist_pt_leadboson_fatjet", "pT of leadboson", 80,0,1800);
    TH1D* hist_eta_leadboson_fatjet = new TH1D ("hist_eta_leadboson_fatjet", "eta of leadboson", 80,-6,6);
    TH1D* hist_phi_leadboson_fatjet = new TH1D ("hist_phi_leadboson_fatjet", "phi of leadboson", 80,-6,6);
    TH1D* hist_m_leadboson_msoftdrop = new TH1D ("hist_m_leadboson_msoftdrop"," msoftdrop of leadboson (mass)", 80,0,150);

    TH1D* hist_pt_subleadboson_fatjet = new TH1D ("hist_pt_subleadboson_fatjet", "pT of subleadboson", 80,0,1800);
    TH1D* hist_eta_subleadboson_fatjet = new TH1D ("hist_eta_subleadboson_fatjet", "eta of subleadboson", 80,-6,6);
    TH1D* hist_phi_subleadboson_fatjet = new TH1D ("hist_phi_subleadboson_fatjet", "phi of subleadboson", 80,-6,6);
    TH1D* hist_m_subleadboson_msoftdrop = new TH1D ("hist_m_subleadboson_msoftdrop"," msoftdrop of subleadboson (mass)", 80,0,150);

    TH1D* hist_mjj_mass_of_twoVBFjets = new TH1D ("hist_mjj_mass_of_twoVBFjets"," mjj_mass_of_twoVBFjets", 80,0,2500);
    TH1D* hist_absDelta_eta_of_twoVBFjets = new TH1D ("hist_absDelta_eta_of_twoVBFjets"," absDelta_eta_mass_of_twoVBFjets", 80,0,10);
    TH1D* hist_mass_HBosonBoson_system = new TH1D ("hist_mass_HBosonBoson_system"," mass of H_Boson_Boson system", 80,0,3000);

    // 29seb hists
    TH1D* hist_pt_scalarsum_VVH_system = new TH1D ("hist_pt_scalarsum_VVH_system"," pt-scalar sum VVH", 80,0,3000);
    TH1D* hist_Xbb_score = new TH1D ("hist_Xbb_score"," Xbb score", 80,0,1);
    TH1D* hist_Vlead_score = new TH1D ("hist_Vlead_score"," Xbb Vlead_score", 80,0,1);
    TH1D* hist_Vsublead_score = new TH1D ("hist_Vsublead_score"," Xbb Vsublead_score", 80,0,1);
    TH1D* hist_btag_score = new TH1D ("hist_btag_score"," b tag score", 80,0,1);
    TH1D* hist_btag_number_inevent = new TH1D ("hist_btag_number_inevent"," btag_number_inevent", 10,0,10);

    TH1D* hist_WvsQCD_Vlead = new TH1D ("hist_WvsQCD_Vlead"," WvsQCD_Vlead", 80,0,1);
    TH1D* hist_WvsQCD_Vsublead = new TH1D ("hist_WvsQCD_Vsublead"," WvsQCD_Vsublead", 80,0,1);
    TH1D* hist_ZvsQCD_Vlead = new TH1D ("hist_ZvsQCD_Vlead"," ZvsQCD_Vlead", 80,0,1);
    TH1D* hist_ZvsQCD_Vsublead = new TH1D ("hist_ZvsQCD_Vsublead"," ZvsQCD_Vsublead", 80,0,1);
    TH1D* hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead = new TH1D ("hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead"," _Vlead", 80,0,1);
    TH1D* hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead = new TH1D ("hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead"," _Vsublead", 80,0,1);




    double genEventSumw[333];
    Long64_t genEventCount[333];
    chain1->SetBranchAddress("genEventCount",&genEventCount);
    chain1->SetBranchAddress("genEventSumw",&genEventSumw);
    int no_runs= chain1->GetEntries();





    int numberm=0;
    int numberm1=0;
    int overlab1=0;
    int cut1=0;
    int cut2=0;
    int cut3=0;
    int cut4=0;
    int cut5=0;
    int cut6=0;
    int cut7=0;
    int cut8=0;
    int cut9=0;
    int cut10=0;
    int cut11=0;
    int nooffat3=0;
    float sumweights=0;
    float sumweights1=0;
    float events_count=0;
    int Nb_lose_nonoverlabbing=0;
    int position_first_quark_with_high_mqq=0;
    int position_second_quark_with_high_mqq=0;




    // for (unsigned ifile2 = 0; ifile2 < input_files.size(); ifile2++)
    // {
    //      TFile* f2 = new TFile(input_files[ifile2]);
    //      TTree* t2 = (TTree*) f2->Get("Runs");
    //      nt.Init(t2);
    //      for (int iii = 0; iii < t2->GetEntries(); ++iii)
    //      {
    //          nt.GetEntry(iii);
    //          // std::cout << "sum: " << sumweights<<std::endl;
    //          //   std::cout << "nt.genEventSumw()[0]: " << nt.genEventSumw()[0]<<std::endl;
    //          sumweights=sumweights+nt.genEventSumw()[0];
    //          events_count=events_count+nt.genEventCount()[0];
    //          // std::cout << "event: " << iii<<std::endl;
    //
    //      }
    //
    // }

    for (int iii = 0; iii < no_runs; iii++)
    {
        chain1->GetEntry(iii);
        // cout << "sum: " << sumweights<<endl;
        //   cout << "genEventSumw[0]: " << genEventSumw[0]<<endl;
        sumweights=sumweights+genEventSumw[0];
        events_count=events_count+genEventCount[0];

        // cout << "event: " << iii<<endl;


    }

    std::cout << "summweights: " << sumweights<<std::endl;
    // std::cout << "summweights1: " << sumweights<<std::endl;

    for (unsigned ifile1 = 0; ifile1 < input_files.size(); ifile1++)
    {
        TFile* f1 = new TFile(input_files[ifile1]);
        TTree* t1 = (TTree*) f1->Get("Events");
        nt.Init(t1);

        for (int i=0; i< t1->GetEntries(); i++)
        {
            nt.GetEntry(i);
            int btag_number_inevent=0;
            if(i% 10000 ==0) std::cout<<i<<std::endl;
            // int Zsublead_index = 9999;
            // int Zlead_index= 9999;
            // int x= 9999;
            // int y=9999;


            if (nt.nFatJet()>0)
            {
                // nevents++;

                // for (int f1 = 0; f1 < nJet[0]; f1++)
                // {
                //   // use the loose btage selection
                //   if (nt.Jet_btagDeepFlavB()[f1]>0.0490 && Jet_pt[f1]>30)
                //   {
                //     vec_btag_score.push_back(nt.Jet_btagDeepFlavB()[f1]);
                //     vec_btag_4d.push_back({nt.Jet_pt[f1],Jet_eta[f1],Jet_phi[f1],Jet_mass[f1]});
                //
                //   }
                // }
                // do the events weights:
                float weight_of_eachevent= (nt.genWeight() /sumweights)*cross_section*1000*137;
                //doing the signal region selction (in this part (i assume i dont know the gen level information and procced from that so i start with all the events i had in the beginging))
                if (nt.nJet()>=2 && nt.nFatJet()>=3)
                {
                    numberm++;// create the histograms
    TH1D* hist_pt_leadVBFQuark = new TH1D ("hist_pt_leadVBFQuark", "pT of leading VBFquark", 80,0,250);
    TH1D* hist_pt_subleadVBFQuark = new TH1D ("hist_pt_subleadVBFQuark", "pT of subleading VBFquark", 80,0,160);
    TH1D* hist_eta_leadVBFQuark = new TH1D ("hist_eta_leadVBFQuark", "eta of leading VBFquark", 80,-6,6);
    TH1D* hist_eta_subleadVBFQuark = new TH1D ("hist_eta_subleadVBFQuark", "eta of subleading VBFquark", 80,-6,6);
    TH1D* hist_phi_leadVBFQuark = new TH1D ("hist_phi_leadVBFQuark", "phi of leading VBFquark", 80,-6,6);
    TH1D* hist_phi_subleadVBFQuark = new TH1D ("hist_phi_subleadVBFQuark", "phi of subleading VBFquark", 80,-6,6);

    TH1D* hist_pt_H_fatjet = new TH1D ("hist_pt_H_fatjet", "pT of Higgs", 80,0,1800);
    TH1D* hist_eta_H_fatjet = new TH1D ("hist_eta_H_fatjet", "eta of Higgs", 80,-6,6);
    TH1D* hist_phi_H_fatjet = new TH1D ("hist_phi_H_fatjet", "phi of Higgs", 80,-6,6);
    TH1D* hist_m_H_msoftdrop = new TH1D ("hist_m_H_msoftdrop"," msoftdrop of H (mass)", 80,0,150);

    TH1D* hist_pt_leadboson_fatjet = new TH1D ("hist_pt_leadboson_fatjet", "pT of leadboson", 80,0,1800);
    TH1D* hist_eta_leadboson_fatjet = new TH1D ("hist_eta_leadboson_fatjet", "eta of leadboson", 80,-6,6);
    TH1D* hist_phi_leadboson_fatjet = new TH1D ("hist_phi_leadboson_fatjet", "phi of leadboson", 80,-6,6);
    TH1D* hist_m_leadboson_msoftdrop = new TH1D ("hist_m_leadboson_msoftdrop"," msoftdrop of leadboson (mass)", 80,0,150);

    TH1D* hist_pt_subleadboson_fatjet = new TH1D ("hist_pt_subleadboson_fatjet", "pT of subleadboson", 80,0,1800);
    TH1D* hist_eta_subleadboson_fatjet = new TH1D ("hist_eta_subleadboson_fatjet", "eta of subleadboson", 80,-6,6);
    TH1D* hist_phi_subleadboson_fatjet = new TH1D ("hist_phi_subleadboson_fatjet", "phi of subleadboson", 80,-6,6);
    TH1D* hist_m_subleadboson_msoftdrop = new TH1D ("hist_m_subleadboson_msoftdrop"," msoftdrop of subleadboson (mass)", 80,0,150);

    TH1D* hist_mjj_mass_of_twoVBFjets = new TH1D ("hist_mjj_mass_of_twoVBFjets"," mjj_mass_of_twoVBFjets", 80,0,2500);
    TH1D* hist_absDelta_eta_of_twoVBFjets = new TH1D ("hist_absDelta_eta_of_twoVBFjets"," absDelta_eta_mass_of_twoVBFjets", 80,0,10);
    TH1D* hist_mass_HBosonBoson_system = new TH1D ("hist_mass_HBosonBoson_system"," mass of H_Boson_Boson system", 80,0,3000);

    // 29seb hists
    TH1D* hist_pt_scalarsum_VVH_system = new TH1D ("hist_pt_scalarsum_VVH_system"," pt-scalar sum VVH", 80,0,3000);
    TH1D* hist_Xbb_score = new TH1D ("hist_Xbb_score"," Xbb score", 80,0,1);
    TH1D* hist_Vlead_score = new TH1D ("hist_Vlead_score"," Xbb Vlead_score", 80,0,1);
    TH1D* hist_Vsublead_score = new TH1D ("hist_Vsublead_score"," Xbb Vsublead_score", 80,0,1);
    TH1D* hist_btag_score = new TH1D ("hist_btag_score"," b tag score", 80,0,1);
    TH1D* hist_btag_number_inevent = new TH1D ("hist_btag_number_inevent"," btag_number_inevent", 10,0,10);

    TH1D* hist_WvsQCD_Vlead = new TH1D ("hist_WvsQCD_Vlead"," WvsQCD_Vlead", 80,0,1);
    TH1D* hist_WvsQCD_Vsublead = new TH1D ("hist_WvsQCD_Vsublead"," WvsQCD_Vsublead", 80,0,1);
    TH1D* hist_ZvsQCD_Vlead = new TH1D ("hist_ZvsQCD_Vlead"," ZvsQCD_Vlead", 80,0,1);
    TH1D* hist_ZvsQCD_Vsublead = new TH1D ("hist_ZvsQCD_Vsublead"," ZvsQCD_Vsublead", 80,0,1);
    TH1D* hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead = new TH1D ("hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead"," _Vlead", 80,0,1);
    TH1D* hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead = new TH1D ("hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead"," _Vsublead", 80,0,1);




    double genEventSumw[333];
    Long64_t genEventCount[333];
    chain1->SetBranchAddress("genEventCount",&genEventCount);
    chain1->SetBranchAddress("genEventSumw",&genEventSumw);
    int no_runs= chain1->GetEntries();





    int numberm=0;
    int numberm1=0;
    int overlab1=0;
    int cut1=0;
    int cut2=0;
    int cut3=0;
    int cut4=0;
    int cut5=0;
    int cut6=0;
    int cut7=0;
    int cut8=0;
    int cut9=0;
    int cut10=0;
    int cut11=0;
    int nooffat3=0;
    float sumweights=0;
    float sumweights1=0;
    float events_count=0;
    int Nb_lose_nonoverlabbing=0;
    int position_first_quark_with_high_mqq=0;
    int position_second_quark_with_high_mqq=0;




    // for (unsigned ifile2 = 0; ifile2 < input_files.size(); ifile2++)
    // {
    //      TFile* f2 = new TFile(input_files[ifile2]);
    //      TTree* t2 = (TTree*) f2->Get("Runs");
    //      nt.Init(t2);
    //      for (int iii = 0; iii < t2->GetEntries(); ++iii)
    //      {
    //          nt.GetEntry(iii);
    //          // std::cout << "sum: " << sumweights<<std::endl;
    //          //   std::cout << "nt.genEventSumw()[0]: " << nt.genEventSumw()[0]<<std::endl;
    //          sumweights=sumweights+nt.genEventSumw()[0];
    //          events_count=events_count+nt.genEventCount()[0];
    //          // std::cout << "event: " << iii<<std::endl;
    //
    //      }
    //
    // }

    for (int iii = 0; iii < no_runs; iii++)
    {
        chain1->GetEntry(iii);
        // cout << "sum: " << sumweights<<endl;
        //   cout << "genEventSumw[0]: " << genEventSumw[0]<<endl;
        sumweights=sumweights+genEventSumw[0];
        events_count=events_count+genEventCount[0];

        // cout << "event: " << iii<<endl;


    }

    std::cout << "summweights: " << sumweights<<std::endl;
    // std::cout << "summweights1: " << sumweights<<std::endl;

    for (unsigned ifile1 = 0; ifile1 < input_files.size(); ifile1++)
    {
        TFile* f1 = new TFile(input_files[ifile1]);
        TTree* t1 = (TTree*) f1->Get("Events");
        nt.Init(t1);

        for (int i=0; i< t1->GetEntries(); i++)
        {
            nt.GetEntry(i);
            int btag_number_inevent=0;
            if(i% 10000 ==0) std::cout<<i<<std::endl;
            // int Zsublead_index = 9999;
            // int Zlead_index= 9999;
            // int x= 9999;
            // int y=9999;


            if (nt.nFatJet()>0)
                }
                for (UInt_t i1 = 0; i1 < nt.nJet(); i1++)
                {
                    if (nt.Jet_pt()[i1]>30 && TMath::Abs(nt.Jet_eta()[i1]<4.5) &&nt.Jet_jetId()[i1]>2)
                    {
                        ak4_pt_eta_cut.push_back({nt.Jet_pt()[i1],nt.Jet_eta()[i1],nt.Jet_phi()[i1],nt.Jet_mass()[i1]});

                    }
                }

                for (UInt_t i2 = 0; i2 < nt.nFatJet(); i2++)
                {
                    if (nt.FatJet_pt()[i2]>250 &&nt.FatJet_msoftdrop()[i2]>40 && TMath::Abs(nt.FatJet_eta()[i2]<4.5))
                    {
                        ak8_pt_msoftdrop_cut_4d.push_back({nt.FatJet_pt()[i2],nt.FatJet_eta()[i2],nt.FatJet_phi()[i2],nt.FatJet_mass()[i2]});
                        vec_H_score.push_back(nt.FatJet_particleNetMD_Xbb()[i2]/(nt.FatJet_particleNetMD_Xbb()[i2]+nt.FatJet_particleNetMD_QCD()[i2]));
                        vec_msoftdrop.push_back(nt.FatJet_msoftdrop()[i2]);

                        vec_WvsQCD_score.push_back(nt.FatJet_particleNet_WvsQCD()[i2]);
                        vec_ZvsQCD_score.push_back(nt.FatJet_particleNet_ZvsQCD()[i2]);
                        vec_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_XCD_score.push_back((nt.FatJet_particleNetMD_Xqq()[i2]+nt.FatJet_particleNetMD_Xcc()[i2])/(nt.FatJet_particleNetMD_Xqq()[i2]+nt.FatJet_particleNetMD_Xcc()[i2]+nt.FatJet_particleNetMD_QCD()[i2]));





                    }
                }


                numberm1++;
                for (int i3 = 0; i3 < ak4_pt_eta_cut.size(); i3++)
                {
                    for (int i4 = 0; i4 < ak8_pt_msoftdrop_cut_4d.size(); i4++)
                    {
                        double drrr1= sqrt(pow(TMath::Abs(ak4_pt_eta_cut[i3].eta()-ak8_pt_msoftdrop_cut_4d[i4].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(ak4_pt_eta_cut[i3],ak8_pt_msoftdrop_cut_4d[i4])),2));
                        if (drrr1<0.8)
                        {
                            marker.push_back(1);
                            overlab1++;
                            //std::cout << "overlabevent: " << i <<std::endl;
                        }
                    }
                    //std::cout << "marker size: " <<marker.size() << "event: " << i <<std::endl;
                    //std::cout << "i3: " << i3<< "event : " <<i << std::endl;
                    if (marker.size()==0)
                    {
                        ak4_pt_eta_cut_overlap_4d.push_back({ak4_pt_eta_cut[i3].pt(),ak4_pt_eta_cut[i3].eta(),ak4_pt_eta_cut[i3].phi(),ak4_pt_eta_cut[i3].mass()});
                    }
                    marker.clear();
                }
                if (ak4_pt_eta_cut_overlap_4d.size()>=2)
                {
                    cut1++;
                    if (ak8_pt_msoftdrop_cut_4d.size()>=3)
                    {
                        cut2++;
                        //std::cout << "ak4_pt_eta_cut_overlap_4d.size(): " <<ak4_pt_eta_cut_overlap_4d.size()<< std::endl;

                            //std::cout <<"i5:"<<i5<< std::endl;
                        for (int i6 = 0; i6 < ak4_pt_eta_cut_overlap_4d.size(); i6++)
                        {

                            //std::cout <<"i6:"<<i6<< std::endl;
                            // inariant_mass_compare.push_back((ak4_pt_eta_cut_overlap_4d[i5]+ak4_pt_eta_cut_overlap_4d[i6]).mass());
                            // std::cout << "inariant_mass_compare: "<< (ak4_pt_eta_cut_overlap_4d[i5]+ak4_pt_eta_cut_overlap_4d[i6]).mass()<< std::endl;
                            // std::cout << "i5: " << i5 <<std::endl;
                            // std::cout << "i6: " << i6 <<std::endl;

                            // inariant_mass_compare_index_2d.push_back({i5,i6});

                            //  using the Max-E scheme
                            // cout<< "event" << i<< endl;
                            // cout << "eta:" << ak4_pt_eta_cut_overlap_4d[i6].eta()<<endl;
                            // cout << "energy:" << ak4_pt_eta_cut_overlap_4d[i6].energy()<<endl;
                            // cout << "index:" <<i6<<endl;


                            if (ak4_pt_eta_cut_overlap_4d[i6].eta()>0)
                            {
                                vec_lead_sublead_vbfquarks_positive_eta.push_back(ak4_pt_eta_cut_overlap_4d[i6].energy());
                                vec_lead_sublead_vbfquarks_positive_eta_index.push_back(i6);
                            }

                            if (ak4_pt_eta_cut_overlap_4d[i6].eta()<0)
                            {
                                vec_lead_sublead_vbfquarks_negative_eta.push_back(ak4_pt_eta_cut_overlap_4d[i6].energy());
                                vec_lead_sublead_vbfquarks_negative_eta_index.push_back(i6);
                            }


                        }
                        if (vec_lead_sublead_vbfquarks_positive_eta.size()>=1 && vec_lead_sublead_vbfquarks_negative_eta.size()>=1)
                        {
                            position_first_quark_with_high_mqq=vec_lead_sublead_vbfquarks_positive_eta_index[max_element(vec_lead_sublead_vbfquarks_positive_eta.begin(),vec_lead_sublead_vbfquarks_positive_eta.end())-vec_lead_sublead_vbfquarks_positive_eta.begin()];
                            position_second_quark_with_high_mqq=vec_lead_sublead_vbfquarks_negative_eta_index[max_element(vec_lead_sublead_vbfquarks_negative_eta.begin(),vec_lead_sublead_vbfquarks_negative_eta.end())-vec_lead_sublead_vbfquarks_negative_eta.begin()];
                        }
                        if (vec_lead_sublead_vbfquarks_positive_eta.size()>=2 && vec_lead_sublead_vbfquarks_negative_eta.size()<1)
                        {
                            position_first_quark_with_high_mqq=vec_lead_sublead_vbfquarks_positive_eta_index[max_element(vec_lead_sublead_vbfquarks_positive_eta.begin(),vec_lead_sublead_vbfquarks_positive_eta.end())-vec_lead_sublead_vbfquarks_positive_eta.begin()];
                            vec_lead_sublead_vbfquarks_positive_eta[max_element(vec_lead_sublead_vbfquarks_positive_eta.begin(),vec_lead_sublead_vbfquarks_positive_eta.end())-vec_lead_sublead_vbfquarks_positive_eta.begin()]=0;
                            position_second_quark_with_high_mqq=vec_lead_sublead_vbfquarks_positive_eta_index[max_element(vec_lead_sublead_vbfquarks_positive_eta.begin(),vec_lead_sublead_vbfquarks_positive_eta.end())-vec_lead_sublead_vbfquarks_positive_eta.begin()];

                        }
                        if (vec_lead_sublead_vbfquarks_positive_eta.size()<1 && vec_lead_sublead_vbfquarks_negative_eta.size()>=2)
                        {
                            position_first_quark_with_high_mqq=vec_lead_sublead_vbfquarks_negative_eta_index[max_element(vec_lead_sublead_vbfquarks_negative_eta.begin(),vec_lead_sublead_vbfquarks_negative_eta.end())-vec_lead_sublead_vbfquarks_negative_eta.begin()];
                            vec_lead_sublead_vbfquarks_negative_eta[max_element(vec_lead_sublead_vbfquarks_negative_eta.begin(),vec_lead_sublead_vbfquarks_negative_eta.end())-vec_lead_sublead_vbfquarks_negative_eta.begin()]=0;
                            position_second_quark_with_high_mqq=vec_lead_sublead_vbfquarks_negative_eta_index[max_element(vec_lead_sublead_vbfquarks_negative_eta.begin(),vec_lead_sublead_vbfquarks_negative_eta.end())-vec_lead_sublead_vbfquarks_negative_eta.begin()];

                        }


                        // int position_first_quark_with_high_mqq=inariant_mass_compare_index_2d[max_element(inariant_mass_compare.begin(),inariant_mass_compare.end())-inariant_mass_compare.begin()][0];
                        // int position_second_quark_with_high_mqq=inariant_mass_compare_index_2d[max_element(inariant_mass_compare.begin(),inariant_mass_compare.end())-inariant_mass_compare.begin()][1];
                        // cout << "first ppostion:" <<  position_first_quark_with_high_mqq<<endl;
                        // cout << "second ppostion:" <<  position_second_quark_with_high_mqq<<endl;

                        if (TMath::Abs(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta()-ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta())>3)
                        {
                            cut3++;
                            if ((ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq]+ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq]).mass()>700)
                            {
                                cut4++;
                                if ((TMath::Abs(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta()-ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta()))>5)
                                {
                                    cut5++;
                                    int position_max_H_score=max_element(vec_H_score.begin(),vec_H_score.end())-vec_H_score.begin();
                                    if (vec_H_score[position_max_H_score]>0.8)
                                    {
                                        cut6++;

                                        for (int i8 = 0; i8 < ak8_pt_msoftdrop_cut_4d.size(); i8++)
                                        {
                                            if (i8!=position_max_H_score)
                                            {
                                                vec_lead_sublead_bosons_4d.push_back({ak8_pt_msoftdrop_cut_4d[i8].pt(),ak8_pt_msoftdrop_cut_4d[i8].eta(),ak8_pt_msoftdrop_cut_4d[i8].phi(),ak8_pt_msoftdrop_cut_4d[i8].mass()});
                                                vec_msoftdrop_two_bosons.push_back(vec_msoftdrop[i8]);
                                                vec_V_score.push_back(vec_H_score[i8]);

                                                vec_Vboson_WvsQCD_score.push_back(vec_WvsQCD_score[i8]);
                                                vec_Vboson_ZvsQCD_score.push_back(vec_ZvsQCD_score[i8]);
                                                vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score.push_back(vec_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_XCD_score[i8]);



                                            }
                                        }


                                        // take the other two vv bosons to be the ones with the highest pt after we exclude the highest xbb score from the fat jets to be the higgs
                                        //cout << "event number: " << i<< endl;


                                        for (int ss1 = 0; ss1 < vec_lead_sublead_bosons_4d.size(); ss1++)
                                        {
                                            vec_lead_sublead_bosons_pt_tocompare.push_back(vec_lead_sublead_bosons_4d[ss1].pt());
                                            // cout << "index of boson: " << ss1<< endl;
                                            // cout << "pt of boson: " << vec_lead_sublead_bosons_4d[ss1].pt()<< endl;
                                        }

                                        int v0 =max_element(vec_lead_sublead_bosons_pt_tocompare.begin(),vec_lead_sublead_bosons_pt_tocompare.end())-vec_lead_sublead_bosons_pt_tocompare.begin();
                                        vec_lead_sublead_bosons_pt_tocompare[v0]=0;
                                        int v1 =max_element(vec_lead_sublead_bosons_pt_tocompare.begin(),vec_lead_sublead_bosons_pt_tocompare.end())-vec_lead_sublead_bosons_pt_tocompare.begin();
                                        // cout << "index of first boson: " << v0<< endl;
                                        // cout << "index of second boson: " << v1<< endl;



                                        for (int f1 = 0; f1 < nt.nJet(); f1++)
                                        {
                                            // use the loose btage selection
                                            if (nt.Jet_btagDeepFlavB()[f1]>0.0490 && nt.Jet_pt()[f1]>30)
                                            {
                                                vec_btag_score.push_back(nt.Jet_btagDeepFlavB()[f1]);
                                                vec_btag_4d.push_back({nt.Jet_pt()[f1],nt.Jet_eta()[f1],nt.Jet_phi()[f1],nt.Jet_mass()[f1]});

                                            }
                                        }


                                        if ((vec_lead_sublead_bosons_4d[v0].pt()>vec_lead_sublead_bosons_4d[v1].pt() && vec_Vboson_ZvsQCD_score[v0]>0.4) ||	(vec_lead_sublead_bosons_4d[v1].pt()>vec_lead_sublead_bosons_4d[v0].pt() && vec_Vboson_ZvsQCD_score[v1]>0.4))
                                        {
                                            cut7++;

                                            if ((vec_lead_sublead_bosons_4d[v0].pt()>vec_lead_sublead_bosons_4d[v1].pt() && vec_Vboson_ZvsQCD_score[v1]>0.4) ||	(vec_lead_sublead_bosons_4d[v1].pt()>vec_lead_sublead_bosons_4d[v0].pt() && vec_Vboson_ZvsQCD_score[v0]>0.4))
                                            {
                                                cut8++;
                                                if ((ak8_pt_msoftdrop_cut_4d[position_max_H_score].pt()+vec_lead_sublead_bosons_4d[v0].pt()+vec_lead_sublead_bosons_4d[v1].pt())>1800)
                                                {
                                                    cut9++;
                                                    if (vec_msoftdrop[position_max_H_score]<130)
                                                    {
                                                        cut10++;
                                                        if (vec_msoftdrop_two_bosons[v0]<130 && vec_msoftdrop_two_bosons[v1]<130)
                                                        {
                                                            cut11++;


                                                            // compare overlapping of btag jets with the higgs max xbb score and then i would do it inside the below loop when the xbb isn't max to compare the btagged b with the other b's which resukted in the VV H_Boson_Boson
                                                            for (int f3 = 0; f3 < vec_btag_score.size(); f3++)
                                                            {


                                                                double drrr2= sqrt(pow(TMath::Abs(vec_btag_4d[f3].eta()-ak8_pt_msoftdrop_cut_4d[position_max_H_score].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec_btag_4d[f3],ak8_pt_msoftdrop_cut_4d[position_max_H_score])),2));
                                                                double drrr3= sqrt(pow(TMath::Abs(vec_btag_4d[f3].eta()-vec_lead_sublead_bosons_4d[v0].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec_btag_4d[f3],vec_lead_sublead_bosons_4d[v0])),2));
                                                                double drrr4= sqrt(pow(TMath::Abs(vec_btag_4d[f3].eta()-vec_lead_sublead_bosons_4d[v1].eta()),2)+pow(TMath::Abs(ROOT::Math::VectorUtil::DeltaPhi(vec_btag_4d[f3],vec_lead_sublead_bosons_4d[v1])),2));

                                                                if (drrr2>0.8 && drrr3>0.8 && drrr4>0.8)
                                                                {
                                                                    Nb_lose_nonoverlabbing++;
                                                                    hist_btag_score->Fill(vec_btag_score[f3],weight_of_eachevent);
                                                                    btag_number_inevent++;

                                                                }
                                                            }







weight_of_eachevent

                                                            if (ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].pt()>ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].pt())
                                                            {
                                                                hist_pt_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].pt(),weight_of_eachevent);
                                                                hist_pt_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].pt(),weight_of_eachevent);
                                                                hist_eta_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta(),weight_of_eachevent);
                                                                hist_eta_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta(),weight_of_eachevent);
                                                                hist_phi_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].phi(),weight_of_eachevent);
                                                                hist_phi_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].phi(),weight_of_eachevent);

                                                            }
                                                            else
                                                            {
                                                                hist_pt_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].pt(),weight_of_eachevent);
                                                                hist_pt_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].pt(),weight_of_eachevent);
                                                                hist_eta_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta(),weight_of_eachevent);
                                                                hist_eta_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta(),weight_of_eachevent);
                                                                hist_phi_leadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].phi(),weight_of_eachevent);
                                                    // }            hist_phi_subleadVBFQuark->Fill(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].phi(),weight_of_eachevent);

                                                            }
                                                            // create mjj (invariant mass of the two vbf jets)
                                                            hist_mjj_mass_of_twoVBFjets->Fill((ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq]+ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq]).mass(),weight_of_eachevent);
                                                            // get the abs eta of the two vbf quarks
                                                            hist_absDelta_eta_of_twoVBFjets->Fill(TMath::Abs(ak4_pt_eta_cut_overlap_4d[position_first_quark_with_high_mqq].eta()-ak4_pt_eta_cut_overlap_4d[position_second_quark_with_high_mqq].eta()),weight_of_eachevent);



                                                            // int position_max_H_score=max_element(vec_H_score.begin(),vec_H_score.end())-vec_H_score.begin();
                                                            hist_pt_H_fatjet->Fill(ak8_pt_msoftdrop_cut_4d[position_max_H_score].pt(),weight_of_eachevent);
                                                            hist_eta_H_fatjet->Fill(ak8_pt_msoftdrop_cut_4d[position_max_H_score].eta(),weight_of_eachevent);
                                                            hist_phi_H_fatjet->Fill(ak8_pt_msoftdrop_cut_4d[position_max_H_score].phi(),weight_of_eachevent);
                                                            hist_m_H_msoftdrop->Fill(vec_msoftdrop[position_max_H_score],weight_of_eachevent);
                                                            // if (ak8_pt_msoftdrop_cut_4d.size()==3)
                                                            // {
                                                            nooffat3++;


                                                            hist_btag_number_inevent->Fill(btag_number_inevent);
                                                            // std::cout <<"event: "<< i <<std::endl;
                                                            // std::cout <<"btag_number_inevent:" <<btag_number_inevent<<std::endl;



                                                            if (vec_lead_sublead_bosons_4d[v0].pt()>vec_lead_sublead_bosons_4d[v1].pt())
                                                            {
                                                                hist_pt_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].pt(),weight_of_eachevent);
                                                                hist_pt_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].pt(),weight_of_eachevent);
                                                                hist_eta_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].eta(),weight_of_eachevent);
                                                                hist_eta_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].eta(),weight_of_eachevent);
                                                                hist_phi_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].phi(),weight_of_eachevent);
                                                                hist_phi_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].phi(),weight_of_eachevent);
                                                                hist_m_leadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[v0],weight_of_eachevent);
                                                                hist_m_subleadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[v1],weight_of_eachevent);

                                                                hist_Vlead_score->Fill(vec_V_score[v0],weight_of_eachevent);
                                                                hist_Vsublead_score->Fill(vec_V_score[v1],weight_of_eachevent);

                                                                hist_WvsQCD_Vlead->Fill(vec_Vboson_WvsQCD_score[v0],weight_of_eachevent);
                                                                hist_WvsQCD_Vsublead->Fill(vec_Vboson_WvsQCD_score[v1],weight_of_eachevent);
                                                                hist_ZvsQCD_Vlead->Fill(vec_Vboson_ZvsQCD_score[v0],weight_of_eachevent);
                                                                hist_ZvsQCD_Vsublead->Fill(vec_Vboson_ZvsQCD_score[v1],weight_of_eachevent);
                                                                hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead->Fill(vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score[v0],weight_of_eachevent);
                                                                hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead->Fill(vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score[v1],weight_of_eachevent);




                                                            }
                                                            else
                                                            {
                                                                hist_pt_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].pt(),weight_of_eachevent);
                                                                hist_pt_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].pt(),weight_of_eachevent);
                                                                hist_eta_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].eta(),weight_of_eachevent);
                                                                hist_eta_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].eta(),weight_of_eachevent);
                                                                hist_phi_leadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v1].phi(),weight_of_eachevent);
                                                                hist_phi_subleadboson_fatjet->Fill(vec_lead_sublead_bosons_4d[v0].phi(),weight_of_eachevent);
                                                                hist_m_leadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[v1],weight_of_eachevent);
                                                                hist_m_subleadboson_msoftdrop->Fill(vec_msoftdrop_two_bosons[v0],weight_of_eachevent);

                                                                hist_Vlead_score->Fill(vec_V_score[v1],weight_of_eachevent);
                                                                hist_Vsublead_score->Fill(vec_V_score[v0],weight_of_eachevent);

                                                                hist_WvsQCD_Vlead->Fill(vec_Vboson_WvsQCD_score[v1],weight_of_eachevent);
                                                                hist_WvsQCD_Vsublead->Fill(vec_Vboson_WvsQCD_score[v0],weight_of_eachevent);
                                                                hist_ZvsQCD_Vlead->Fill(vec_Vboson_ZvsQCD_score[v1],weight_of_eachevent);
                                                                hist_ZvsQCD_Vsublead->Fill(vec_Vboson_ZvsQCD_score[v0],weight_of_eachevent);
                                                                hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead->Fill(vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score[v1],weight_of_eachevent);
                                                                hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead->Fill(vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score[v0],weight_of_eachevent);
                                                            }

                                                            // invariant mass of H_Boson_Boson system
                                                            hist_mass_HBosonBoson_system->Fill(ak8_pt_msoftdrop_cut_4d[position_max_H_score].pt()+vec_lead_sublead_bosons_4d[v0].pt()+vec_lead_sublead_bosons_4d[v1].pt(),weight_of_eachevent);

                                                            hist_pt_scalarsum_VVH_system->Fill((ak8_pt_msoftdrop_cut_4d[position_max_H_score]+vec_lead_sublead_bosons_4d[v0]+vec_lead_sublead_bosons_4d[v1]).mass(),weight_of_eachevent);
                                                            hist_Xbb_score->Fill(vec_H_score[position_max_H_score],weight_of_eachevent);

                                                        }
                                                    }

                                                }

                                            }
                                        }

                                    }

                                }
                            }

                        }
                    }


                }


                ak4_pt_eta_cut.clear();
                ak8_pt_msoftdrop_cut_4d.clear();
                ak4_pt_eta_cut_overlap_4d.clear();
                //ak8_pt_msoftdrop_cut_4d_overlab.clear();
                marker.clear();
                // inariant_mass_compare.clear();
                // inariant_mass_compare_index_2d.clear();
                vec_H_score.clear();
                vec_lead_sublead_bosons_4d.clear();
                vec_msoftdrop_two_bosons.clear();
                vec_msoftdrop.clear();
                vec_V_score.clear();
                vec_btag_score.clear();
                vec_btag_4d.clear();

                vec_WvsQCD_score.clear();
                vec_ZvsQCD_score.clear();
                vec_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_XCD_score.clear();
                vec_Vboson_WvsQCD_score.clear();
                vec_Vboson_ZvsQCD_score.clear();
                vec_Vboson_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_score.clear();

                vec_lead_sublead_vbfquarks_positive_eta.clear();
                vec_lead_sublead_vbfquarks_positive_eta_index.clear();
                vec_lead_sublead_vbfquarks_negative_eta.clear();
                vec_lead_sublead_vbfquarks_negative_eta_index.clear();
                vec_lead_sublead_bosons_pt_tocompare.clear();




            }


        }
    }
    // the first bracked here is for the if condition that nt.nFatJet()s large than zero to start redaing the ttres and all that cuz other events doesnt have fat jet in this root file




    // std::cout << "numberm: " << numberm << std::endl;
    // std::cout << "numberm1: " << numberm1 << std::endl;
    // std::cout << "overlab1: " << overlab1 << std::endl;
    // std::cout << "nooffat3: " << nooffat3 << std::endl;
    float cut1_weighted=0;
    float cut2_weighted=0;
    float cut3_weighted=0;
    float cut4_weighted=0;
    float cut5_weighted=0;
    float cut6_weighted=0;
    float cut7_weighted=0;
    float cut8_weighted=0;
    float cut9_weighted=0;
    float cut10_weighted=0;
    float cut11_weighted=0;
    cut1_weighted=(cut1/events_count)*137*1000*cross_section;
    cut2_weighted=(cut2/events_count)*137*1000*cross_section;
    cut3_weighted=(cut3/events_count)*137*1000*cross_section;
    cut4_weighted=(cut4/events_count)*137*1000*cross_section;
    cut5_weighted=(cut5/events_count)*137*1000*cross_section;
    cut6_weighted=(cut6/events_count)*137*1000*cross_section;
    cut7_weighted=(cut7/events_count)*137*1000*cross_section;
    cut8_weighted=(cut8/events_count)*137*1000*cross_section;
    cut9_weighted=(cut9/events_count)*137*1000*cross_section;
    cut10_weighted=(cut10/events_count)*137*1000*cross_section;
    cut11_weighted=(cut11/events_count)*137*1000*cross_section;
    std::cout << "cut1: " << cut1 << std::endl;
    std::cout << "cut2: " << cut2 << std::endl;
    std::cout << "cut3: " << cut3 << std::endl;
    std::cout << "cut4: " << cut4 << std::endl;
    std::cout << "cut5: " << cut5 << std::endl;
    std::cout << "cut6: " << cut6 << std::endl;
    std::cout << "cut7: " << cut7 << std::endl;
    std::cout << "cut8: " << cut8 << std::endl;
    std::cout << "cut9: " << cut9 << std::endl;
    std::cout << "cut10: " << cut10 << std::endl;
    std::cout << "cut11: " << cut11<< std::endl;
    std::cout << "events_count: " << events_count << std::endl;
    std::cout << "Nb_lose_nonoverlabbing: " << Nb_lose_nonoverlabbing << std::endl;
    std::cout<< "cut1 weighted:" << cut1_weighted<<endl;
    std::cout<< "cut2 weighted:" << cut2_weighted<<endl;
    std::cout<< "cut3 weighted:" << cut3_weighted<<endl;
    std::cout<< "cut4 weighted:" << cut4_weighted<<endl;
    std::cout<< "cut5 weighted:" << cut5_weighted<<endl;
    std::cout<< "cut6 weighted:" << cut6_weighted<<endl;
    std::cout<< "cut7 weighted:" << cut7_weighted<<endl;
    std::cout<< "cut8 weighted:" << cut8_weighted<<endl;
    std::cout<< "cut9 weighted:" << cut9_weighted<<endl;
    std::cout<< "cut10 weighted:" << cut10_weighted<<endl;
    std::cout<< "cut11 weighted:" << cut11_weighted<<endl;
    std::cout<< "nocut weighted:" << (events_count/events_count)*137*1000*cross_section<<endl;
    std::cout<< "error cut1 weighted:" << cut1_weighted *(sqrt(cut1)/cut1)<<endl;
    std::cout<< "error cut2 weighted:" << cut2_weighted *(sqrt(cut2)/cut2)<<endl;
    std::cout<< "error cut3 weighted:" << cut3_weighted *(sqrt(cut3)/cut3)<<endl;
    std::cout<< "error cut4 weighted:" << cut4_weighted *(sqrt(cut4)/cut4)<<endl;
    std::cout<< "error cut5 weighted:" << cut5_weighted *(sqrt(cut5)/cut5)<<endl;
    std::cout<< "error cut6 weighted:" << cut6_weighted *(sqrt(cut6)/cut6)<<endl;
    std::cout<< "error cut7 weighted:" << cut7_weighted *(sqrt(cut7)/cut7)<<endl;
    std::cout<< "error cut8 weighted:" << cut8_weighted *(sqrt(cut8)/cut8)<<endl;
    std::cout<< "error cut9 weighted:" << cut9_weighted *(sqrt(cut9)/cut9)<<endl;
    std::cout<< "error cut10 weighted:" << cut10_weighted *(sqrt(cut10)/cut10)<<endl;
    std::cout<< "error cut11 weighted:" << cut11_weighted *(sqrt(cut11)/cut11)<<endl;
    std::cout<< "error nocut weighted:" << ((events_count/events_count)*137*1000*cross_section)*(sqrt(events_count)/events_count)<<endl;




    f_output->cd();
    hist_pt_leadVBFQuark->Write();
    hist_pt_subleadVBFQuark->Write();
    hist_eta_leadVBFQuark->Write();
    hist_eta_subleadVBFQuark->Write();
    hist_phi_subleadVBFQuark->Write();
    hist_pt_H_fatjet->Write();
    hist_eta_H_fatjet->Write();
    hist_phi_H_fatjet->Write();
    hist_m_H_msoftdrop->Write();
    hist_pt_leadboson_fatjet->Write();
    hist_eta_leadboson_fatjet->Write();
    hist_phi_leadboson_fatjet->Write();
    hist_m_leadboson_msoftdrop->Write();
    hist_pt_subleadboson_fatjet->Write();
    hist_eta_subleadboson_fatjet->Write();
    hist_phi_subleadboson_fatjet->Write();
    hist_m_subleadboson_msoftdrop->Write();
    hist_mjj_mass_of_twoVBFjets->Write();
    hist_absDelta_eta_of_twoVBFjets->Write();
    hist_mass_HBosonBoson_system->Write();
    //29seb
    hist_pt_scalarsum_VVH_system->Write();
    hist_Xbb_score->Write();
    hist_Vlead_score->Write();
    hist_Vsublead_score->Write();
    hist_btag_score->Write();
    hist_btag_number_inevent->Write();

    hist_WvsQCD_Vlead->Write();
    hist_WvsQCD_Vsublead->Write();
    hist_ZvsQCD_Vlead->Write();
    hist_ZvsQCD_Vsublead->Write();
    hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vlead->Write();
    hist_Xqq_plus_Xcc_devided_Xqq_plus_Xcc_plus_QCD_Vsublead->Write();


    // ->Write();



















}
