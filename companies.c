#include <stdio.h>
#include <string.h>
#include "helper.h"
#include "companies.h"

struct company companies[MAX_COMPANIES];

char *company_names_hardware[MAX_COMPANY_NAMES] = { "JeeTech","RejTech","GTech","ZTech","MTech","OgTech","BTech","KaTech","JTech","DTech","ByoTech","ITech","FotTech","QimgTech","QTech","HTech","GTech","PoTech","PuTech","TiTech","FTech","XTech","RTech","VokTech","MetqTech","NiTech","STech","XTech","ETech","KTech","GaTech","KTech","NTech","HedkTech","RoTech","FenwTech","JTech","CaTech","ITech","DTech","KiTech","RafTech","PoaTech","WujTech","MykTech","HuTech","ITech","KTech","XTech","JoTech","IcTech","FTech","RTech","MuTech","PTech","OTech","NTech","ZetlTech","PobnTech","FTech","KTech","PuTech","CirnTech","STech","BTech","LeTech","MTech","BikTech","ETech","YTech","PebpTech","BTech","PapjTech","FTech","SupkTech","AimTech","WeTech","ZTech","KTech","ATech","XaTech","CTech","SemTech","KTech","MTech","WTech","JTech","BieoTech","BerTech","HTech","RTech","ZeTech","SaptTech","MTech","TTech","KusTech","VTech","DiTech","ETech","AzTech","GaTech","CoTech","HTech","SeotTech","QTech","BTech","OTech","DoeTech","ZucTech","WTech","BiTech","UjauTech","HTech","EaxTech","TTech","OTech","VTech","FunTech","JTech","SeloTech","TTech","ITech","LTech","UTech","ATech","TiTech","ATech","VyTech","UiTech","KuTech","YTech","STech","OTech","NTech","KTech","RaehTech","OkaTech","ETech","KuTech","PTech","YisTech","DhmTech","WaTech","GhTech","MTech","PeTech","UosiTech","WakbTech","UpolTech","JTech","FoTech","MhoTech","FTech","AiozTech","KamTech","NuaTech","OTech","BoTech","LuclTech","BahsTech","UTech","LTech","JTech","CoTech","ITech","ETech","QeTech","MoTech","ITech","FiagTech","CaecTech","PTech","STech","TuvTech","IpafTech","DTech","ETech","JeaTech","TosTech","DTech","WTech","LTech","PiTech","CTech","CTech","WTech","FTech","RaiTech","IjiTech","DTech","NTech","KTech","UTech","JTech","JTech","STech","CuvyTech","ATech","UTech","ITech","EmurTech","QTech","ITech","ETech","XTech","EgoTech","HeTech","TTech","AreTech","IefTech","KaTech","ITech","UtTech","VTech","ATech","WuTech","AucaTech","CTech","LeoTech","UliTech","HoTech","LTech","ETech","DTech","EvajTech","LoTech","NioTech","HTech","MTech","BTech","HTech","HTech","WirTech","CTech","BTech","WaTech","KTech","KemeTech","OthhTech","UoepTech","HytcTech","CTech","QaTech","PTech","FTech","NTech","MTech","LeaTech","CTech","KTech","RTech","BuTech","OjabTech","GaueTech","ShriTech","LaTech","GiTech","NTech","AmTech","EjisTech","ATech","FodvTech","FhgaTech","TTech","PTech","QiTech","FijsTech","GiTech","STech","KTech","UubTech","KuooTech","DTech","CTech","RTech","GibdTech","BayTech","NaTech","PTech","GTech","TTech","ITech","EluTech","CajoTech","ATech","ITech","ITech","MehTech","IeuvTech","UTech","TapjTech","ReTech","XTech","SelTech","KTech","DaaTech","JifTech","ZicrTech","OTech","ETech","PyTech","BeplTech","ETech","KoyeTech","BTech","CariTech","NTech","ATech","EceTech","GimTech","HTech","NTech","QioTech","JaTech","UjTech","GTech","RopnTech","EeTech","ATech","CuTech","PTech","VTech","CodTech","GTech","NTech","ETech","YvTech","RisgTech","NTech","DuhTech","DTech","FTech","KiTech","SaiTech","IatiTech","FTech","LTech","DeqTech","GeTech","PodbTech","ZTech","DTech","RTech","NTech","BonxTech","GefoTech","JeTech","HTech","OTech","BoTech","JaisTech","GuvTech","YbolTech","RTech","RTech","SaTech","TTech","ITech","ATech","STech","DTech","WyTech","GTech","CTech","VTech","ATech","OcuTech","UadoTech","CyzTech","GTech","XabTech","GTech","JTech","UgaTech","GojeTech","STech","PTech","SapTech","UwaTech","DTech","BTech","FTech","ETech","BoapTech","NTech","JosnTech","STech","ATech","UTech","CTech","CuutTech","IdhxTech","JTech","EeeTech","HTech","DofTech","ATech","MTech","LTech","JTech","RTech","JTech","FeeeTech","LesrTech","RTech","ATech","MTech","ETech","IlTech","VTech","KirTech","ZTech","ITech","RTech","RalTech","ZTech","RidTech","BofTech","JoTech","DTech","ETech","CurmTech","DakTech","SyTech","BTech","IxopTech","JokvTech","IamiTech","MakjTech","BayhTech","ETech","ZeiuTech","TTech","GhTech","VTech","IozTech","NTech","LTech","DerTech","LupTech","PaTech","TTech","GTech","JosTech","LTech","EibTech","BidcTech","DTech","ITech","DeaTech","HTech","OTech","MoTech","NTech","HhoqTech","AiTech","JagaTech","TyTech","UfTech","LaraTech","GuTech","TuwkTech","ZTech","DepjTech","SisTech","BTech","UvhmTech","FTech","PofdTech","XTech","ChtaTech","LTech","GegTech","RTech","NinTech","ZuvTech","IbyTech","DTech","UTech","FotcTech","VTech","JTech","ErTech","DTech","MTech","FokTech","LTech","OTech","STech","ITech","DTech","LulTech","GiTech","CTech","UTech","DuTech","WihTech","IrTech","LeilTech","STech","MijhTech","ETech","VTech","GTech","WokTech","JTech","GTech","XepTech","NieTech","HarsTech","WTech","UebTech","DuTech","KTech","ATech","BTech","NTech","OTech","UTech","KabTech","PTech","TTech","VTech","GifuTech","FTech","BaupTech","WeTech","KTech","QuTech","JicbTech","ATech","IdTech","RTech","XacdTech","BTech","MTech","LTech","ModTech","YTech","CaTech","KTech","MhqTech","MoTech","GTech","OTech","JTech","NoTech","SujuTech","CTech","CeovTech","YnTech","FyhTech","BeTech","DTech","TeoTech","NTech","WTech","XTech","MyTech","WTech","ETech","NuTech","ETech","OidTech","ATech","FaTech","UTech","ZyTech","LTech","BTech","CTech","TTech","CTech","JTech","RTech","ATech","MTech","STech","VoboTech","PifTech","ObTech","RoTech","GTech","CTech","RoTech","NTech","ATech","ETech","ITech","LTech","PimbTech","ChtiTech","EpTech","PTech","BybhTech","TikTech","PaelTech","RTech","PuTech","STech","PuTech","ToTech","KTech","JTech","CTech","KTech","GTech","PejTech","OTech","JTech","IdTech","LhTech","ETech","RTech","CiTech","STech","JTech","YraqTech","KarcTech","ZTech","OTech","YtTech","GaopTech","OfoTech","BeTech","UlTech","RoTech","JTech","ETech","MatTech","WTech","KieTech","LTech","QanjTech","STech","ETech","UvoTech","EvykTech","FofTech","DTech","JTech","TebcTech","FTech","NTech","MihdTech","OTech","WewTech","ITech","FTech","BTech","BenfTech","UTech","EiuTech","JTech","NijwTech","DTech","EfiwTech","RTech","SoypTech","XacTech","STech","BTech","TitTech","VhTech","PTech","GTech","FasTech","WyntTech","EticTech","ATech","MTech","ModTech","HTech","XTech","NTech","GTech","OroTech","NafbTech","OuliTech","JTech","IcTech","UxTech","OTech","FTech","FeTech","QTech","LTech","ElTech","GTech","TTech","NeTech","OholTech","QepTech","NhhhTech","UTech","CTech","HiffTech","MTech","RutTech","ETech","BakuTech","DuubTech","UcosTech","KeTech","VebaTech","ITech","TTech","UyTech","PTech","WurrTech","MaTech","FoTech","QueTech","TTech","FTech","WTech","ATech","JTech","FTech","PuvTech","JejpTech","EjeTech","DueTech","CynrTech","JTech","MowlTech","PewTech","OlaTech","ETech","QTech","FitmTech","SidTech","JapTech","ATech","UTech","NTech","STech","DojlTech","HTech","JeTech","STech","FaTech","PoaTech","FTech","PTech","MolTech","BakTech","GTech","GuTech","KTech","VoiTech","BTech","WauiTech","AuxuTech","DuTech","TTech","STech","VouTech","MTech","KiTech","LiTech","DiewTech","GaqTech","MTech","BTech","DTech","WTech","OsudTech","QebTech","EnofTech","UfioTech","ZivjTech","PiTech","HocTech","SitTech","ETech","GTech","QTech","GTech","CTech","ZTech","WTech","NaTech","MTech","BTech","WabTech","LodwTech","PuTech","CTech","NifsTech","KTech","HoTech","CheiTech","KyTech","YrupTech","ATech","ImTech","NTech","ITech","MufoTech","FTech","OTech","FTech","WTech","HipoTech","PTech","PTech","FTech","GTech","ObTech","KTech","NuTech","YTech","UTech","RTech","CTech","FoTech","ElaTech","RiTech","DheTech","IlTech","CoTech","ZhsaTech","UTech","PaTech","CuuaTech","GTech","ETech","XiTech","AcTech","BTech","RunpTech","GuuTech","BTech","RTech","NTech","JTech","FTech","UwhlTech","RTech","ITech","HyoTech","YqTech","DiTech","EnaaTech","UlanTech","MoTech","VuTech","TTech","GykTech","GTech","DTech","AyooTech","ETech","BaTech","SemuTech","ATech","CirpTech","CeTech","XaroTech","LelTech","NidTech","HelxTech","NTech","ATech","IrhTech","MomdTech","MTech","PiTech","IcTech","OTech","AgTech","KTech","KTech","ATech","HiTech","TiTech","EregTech","RTech","ATech","VTech","SoTech","CTech","ITech","PeTech","NirTech","GhTech","HTech","JTech","OrTech","BTech","DeTech","DTech","LeveTech","NoTech","SuiTech","EdyTech","DamnTech","VibmTech","SosaTech","LuTech","RTech","LTech","KTech","XyyoTech","GTech","JTech","RTech","MTech","SeTech","DTech","MTech","QoykTech","LTech","ATech","MyuqTech","ETech","UijaTech","LijcTech","GopTech","KTech","NujwTech","IimiTech","NTech","MTech","JapgTech","JauTech","FTech","FTech","LTech","ETech","UTech","KTech","OTech","TavTech","AuTech","VyTech","CiTech","HokbTech","ATech","VidlTech","PiTech","JTech","WTech","WTech","PTech","KTech","PeTech","OTech","TTech","OTech","JolrTech","TTech","ETech","MufTech","MTech","RhoTech","ITech","EgTech","PepcTech","PTech","GardTech","IzTech","KTech","OaTech","SoeTech","PuohTech","MaacTech","OTech","PTech","BugsTech","ATech","DTech","YfadTech","LaTech","KoegTech","UTech","TTech","NohTech","KanTech","NTech","XozTech","UTech","WTech","PoTech","ATech","OTech","YTech","BuntTech","QyrkTech","NTech","MTech","BichTech","NTech","UmTech","VobnTech","ITech","ReuTech","NeTech","BemdTech" };
char *company_names_software[MAX_COMPANY_NAMES] = { "ApeuSoft","DSoft","PSoft","FSoft","MuSoft","EpubSoft","EcSoft","LSoft","OSoft","IejSoft","ZoasSoft","MSoft","GSoft","OgaSoft","HoaoSoft","HukbSoft","DiSoft","EciwSoft","XSoft","IhSoft","LeSoft","PutnSoft","NurSoft","DahSoft","HiSoft","FeugSoft","WSoft","LSoft","PhzeSoft","ESoft","TuSoft","TSoft","ArSoft","AzSoft","VSoft","TyonSoft","AgSoft","VSoft","FihSoft","LSoft","EqujSoft","XouSoft","HusrSoft","BaSoft","HSoft","UwaiSoft","SSoft","ISoft","HSoft","NSoft","PiSoft","NSoft","ByfgSoft","BiSoft","MirSoft","HerpSoft","FidSoft","NiaSoft","YykSoft","MefSoft","ESoft","OSoft","RaySoft","FuhlSoft","GiurSoft","ZSoft","RSoft","DucnSoft","GySoft","LSoft","IbiSoft","RoxSoft","JSoft","BSoft","GSoft","RSoft","TSoft","MSoft","OkiSoft","HibSoft","FSoft","SSoft","ISoft","LSoft","SSoft","NuzcSoft","VuSoft","ESoft","IsiSoft","BietSoft","FSoft","ISoft","OoeSoft","TSoft","SSoft","GuytSoft","DeSoft","JuklSoft","JecSoft","PSoft","IrozSoft","CaeSoft","KijSoft","PSoft","AapSoft","KiSoft","EofeSoft","DSoft","EsSoft","QeheSoft","LSoft","RinvSoft","PSoft","KSoft","TSoft","KSoft","MebSoft","GazcSoft","NSoft","JSoft","LSoft","TSoft","EruSoft","IcSoft","NhkSoft","AepSoft","LSoft","LiarSoft","OSoft","ISoft","TSoft","BiSoft","NSoft","LSoft","FSoft","HSoft","PSoft","PSoft","KemSoft","ESoft","PhSoft","RyosSoft","RSoft","NugsSoft","LSoft","JyiSoft","NSoft","USoft","PuaSoft","FSoft","NSoft","BaSoft","OjSoft","CakiSoft","NSoft","AkytSoft","VoeSoft","RSoft","DSoft","MSoft","GufhSoft","SSoft","SSoft","JSoft","TSoft","QSoft","VSoft","OSoft","JySoft","NelSoft","SSoft","OdidSoft","XoSoft","JSoft","HamSoft","QSoft","RSoft","BacgSoft","CSoft","PSoft","NSoft","OSoft","AisSoft","CinmSoft","PSoft","VSoft","VySoft","LenoSoft","CisSoft","UciSoft","KicrSoft","PSoft","RSoft","VSoft","FefySoft","WelSoft","FSoft","SieSoft","ZaSoft","MefpSoft","OkorSoft","SySoft","GSoft","HeSoft","KSoft","BSoft","TyiSoft","JSoft","MomoSoft","FSoft","FegSoft","UjeSoft","OSoft","JobxSoft","BuSoft","ISoft","AeuSoft","NSoft","ESoft","KaSoft","CecSoft","GSoft","LSoft","SayySoft","YSoft","EoSoft","FiSoft","OSoft","WaoSoft","ESoft","HSoft","CyebSoft","DegiSoft","ISoft","FSoft","TuvSoft","RoSoft","OgSoft","BSoft","GapnSoft","HhSoft","ZSoft","LSoft","JSoft","GudSoft","VSoft","PSoft","CSoft","VSoft","GSoft","RSoft","DuSoft","BaaSoft","FSoft","IelSoft","KynnSoft","XSoft","DeSoft","EjSoft","BakrSoft","SSoft","NiveSoft","JojjSoft","GiSoft","NonkSoft","CSoft","JSoft","GSoft","ASoft","PucmSoft","RSoft","UnSoft","BojSoft","UfoSoft","OSoft","JafSoft","DobhSoft","VSoft","CSoft","PSoft","MSoft","WSoft","CSoft","ESoft","USoft","PuuSoft","YighSoft","PSoft","MaySoft","LySoft","AuSoft","MSoft","ASoft","RiSoft","ESoft","USoft","CoedSoft","QSoft","DijSoft","SemSoft","LiSoft","NSoft","DSoft","JSoft","GaSoft","QSoft","CuSoft","SaiSoft","VSoft","TawgSoft","JuhSoft","InSoft","ISoft","BSoft","YoSoft","CSoft","YSoft","DSoft","NSoft","DSoft","LSoft","ZoSoft","TuSoft","RSoft","AlotSoft","BSoft","LSoft","LSoft","TSoft","XSoft","HeewSoft","RSoft","BSoft","EvakSoft","ChSoft","MeujSoft","IazaSoft","XenSoft","ESoft","MSoft","JuSoft","XusSoft","PSoft","AsykSoft","VevrSoft","NSoft","ASoft","HSoft","RSoft","FadSoft","HSoft","MSoft","FSoft","NSoft","MuduSoft","JiSoft","RaSoft","SiSoft","KSoft","FiSoft","JofSoft","FaSoft","USoft","WiiSoft","FSoft","PSoft","LapuSoft","CSoft","AzhSoft","PelrSoft","QSoft","KSoft","CuSoft","SSoft","DSoft","DipjSoft","SaoSoft","YSoft","CSoft","CehgSoft","QohSoft","AgeSoft","FSoft","VukwSoft","WugSoft","MiSoft","OSoft","ISoft","KSoft","DSoft","KSoft","GudSoft","ChiSoft","VaSoft","KuSoft","ISoft","RSoft","PSoft","PSoft","DoSoft","WoloSoft","MaSoft","KySoft","IuuSoft","ViSoft","JSoft","RSoft","PyaSoft","PSoft","MytiSoft","DasqSoft","NileSoft","DejSoft","HiSoft","BomjSoft","OSoft","DubiSoft","TaysSoft","CSoft","DSoft","TSoft","OcSoft","NSoft","SSoft","QiSoft","JoioSoft","GSoft","MSoft","PalSoft","OSoft","KSoft","SSoft","ESoft","BucSoft","ESoft","SSoft","NitSoft","ASoft","ISoft","ISoft","JSoft","NaiSoft","LSoft","QacSoft","BycSoft","BhpiSoft","LiSoft","ZowsSoft","BuSoft","ItSoft","DSoft","DSoft","NSoft","MSoft","PSoft","OSoft","CuSoft","ReSoft","DSoft","CojmSoft","FSoft","PSoft","KSoft","ZSoft","VSoft","UyriSoft","RudSoft","EfuSoft","FSoft","GySoft","WSoft","SiSoft","OSoft","MeSoft","ErSoft","DSoft","ESoft","FSoft","YjiSoft","XuSoft","ASoft","GeijSoft","FevSoft","DSoft","ASoft","BulsSoft","RiSoft","GembSoft","ESoft","JSoft","ESoft","LSoft","FSoft","USoft","LSoft","PugsSoft","GSoft","YecSoft","QSoft","FitbSoft","JiSoft","VoSoft","ObacSoft","CSoft","PySoft","FSoft","AvhwSoft","ASoft","HSoft","TSoft","BaSoft","ESoft","RSoft","JSoft","JiuSoft","ASoft","TysdSoft","ESoft","ESoft","LabiSoft","OSoft","USoft","JobSoft","SedSoft","VictSoft","GaakSoft","GSoft","JunwSoft","CSoft","HaSoft","NuSoft","ISoft","NhpSoft","BSoft","ZSoft","USoft","OSoft","ModSoft","WhnuSoft","HSoft","FSoft","JSoft","YSoft","DeSoft","USoft","NhtSoft","VacSoft","BSoft","WhshSoft","TajkSoft","WSoft","PSoft","CSoft","ISoft","CyvSoft","PisSoft","YSoft","QodbSoft","PSoft","GSoft","CuSoft","MyiSoft","TSoft","JiSoft","UkozSoft","CSoft","CuzSoft","PoitSoft","ESoft","FSoft","PSoft","FuSoft","HSoft","PucSoft","WoarSoft","BSoft","DazdSoft","ASoft","QSoft","ISoft","FSoft","UhSoft","FSoft","KSoft","ZSoft","OroSoft","OukSoft","PSoft","CSoft","PSoft","FSoft","FSoft","OjuSoft","TuSoft","EsomSoft","VSoft","MSoft","HuSoft","DSoft","DorSoft","AjoSoft","VouSoft","AkehSoft","KSoft","JasSoft","FSoft","TeuSoft","RSoft","JiatSoft","IloSoft","IxytSoft","ZipgSoft","UpSoft","AwoSoft","SuSoft","YSoft","TSoft","OSoft","GuSoft","ISoft","SutSoft","CoptSoft","HSoft","PSoft","SeSoft","MSoft","MehSoft","AeSoft","ASoft","NowSoft","GaggSoft","PioSoft","EhSoft","ReSoft","BSoft","USoft","ESoft","VozSoft","MhSoft","BeSoft","IsufSoft","NSoft","LSoft","IcutSoft","ESoft","OSoft","IkSoft","ASoft","FSoft","PaSoft","OSoft","YSoft","WSoft","QhSoft","OqaSoft","USoft","CikSoft","ESoft","KSoft","PSoft","JSoft","ApeSoft","ESoft","OSoft","WSoft","TokkSoft","IveSoft","MSoft","NevSoft","TSoft","JoSoft","ISoft","ZSoft","OSoft","ShmSoft","ASoft","ESoft","VSoft","MufiSoft","CuSoft","SemSoft","AsuSoft","ESoft","PSoft","MisSoft","BSoft","KSoft","FSoft","HadSoft","SSoft","CSoft","CiSoft","DeSoft","WiSoft","AvakSoft","IwSoft","SawSoft","FSoft","GiSoft","ElabSoft","CikbSoft","MSoft","ESoft","GaqlSoft","ISoft","USoft","RSoft","OmeSoft","RSoft","SSoft","SSoft","LuseSoft","WSoft","DSoft","ASoft","InSoft","KaSoft","ASoft","GumSoft","WaiiSoft","KSoft","SSoft","ASoft","OSoft","MSoft","TaeuSoft","USoft","KSoft","USoft","KSoft","KhSoft","OSoft","TSoft","SSoft","BagiSoft","OSoft","ESoft","PinSoft","OSoft","SeeoSoft","SaSoft","MSoft","EuseSoft","JSoft","LSoft","GhSoft","PSoft","FitvSoft","QSoft","SupSoft","NSoft","ISoft","BSoft","UniiSoft","CSoft","FeoaSoft","PSoft","USoft","CikSoft","NSoft","ASoft","GSoft","BSoft","CSoft","DSoft","KSoft","KoSoft","NorhSoft","GSoft","SubqSoft","SojrSoft","FerSoft","DufSoft","SSoft","NSoft","KengSoft","MSoft","DaSoft","DSoft","EkSoft","CSoft","ZSoft","LaSoft","CoedSoft","MSoft","LoSoft","HSoft","KSoft","YSoft","ESoft","LeunSoft","IkalSoft","FSoft","RaswSoft","CSoft","FSoft","OSoft","ZSoft","CuSoft","ISoft","SasSoft","USoft","TaSoft","UfSoft","LuSoft","JSoft","NoSoft","CSoft","NeeSoft","OkeSoft","VuSoft","TibtSoft","ESoft","LiavSoft","RSoft","FouSoft","DSoft","IbSoft","BSoft","UsSoft","WSoft","EnSoft","MixzSoft","WyqSoft","AzSoft","MSoft","WhdSoft","LaSoft","ISoft","IsSoft","ASoft","KSoft","SSoft","KSoft","MSoft","PeSoft","NaSoft","USoft","LSoft","HSoft","AwSoft","UkSoft","EtSoft","YSoft","PySoft","OSoft","FajuSoft","RSoft","KSoft","KegSoft","DSoft","HSoft","ISoft","ASoft","HSoft","XujtSoft","ZukSoft","XSoft","IgeSoft","SiSoft","KSoft","PSoft","OSoft","PSoft","TedcSoft","JaSoft","BeSoft","RSoft","DSoft","ISoft","YSoft","GileSoft","SiSoft","PSoft","ZSoft","DSoft","TauSoft","WadSoft","LSoft","BuolSoft","MunlSoft","OSoft","DSoft","HSoft","NygeSoft","NSoft","OjSoft","SSoft","HSoft","KiSoft","AxSoft","BSoft","JSoft","ISoft","BycSoft","PiSoft","NySoft","SSoft","JSoft","KhylSoft","TeSoft","LagSoft","AjaiSoft","FSoft","YSoft","OweSoft","FiSoft","WaeSoft","KibSoft","TuepSoft","DaroSoft","FSoft","KiSoft","XSoft","CuSoft","XiSoft","KSoft","VSoft","ZinlSoft","RuSoft","BSoft","AcSoft","WSoft","ASoft","WixoSoft","PijSoft","KaSoft","XylnSoft","NanSoft","CojgSoft","OluSoft","WeSoft","CufSoft","LyuSoft","TSoft","XuSoft","USoft","USoft","GobSoft","UpiSoft","JoiSoft","VSoft","PaiaSoft","RSoft","SSoft","MunSoft","ISoft","YSoft","CSoft","RSoft","AliuSoft","MSoft","GigSoft","NSoft","GuglSoft","MurbSoft","DSoft","CSoft","TSoft","EfSoft","LamSoft","GSoft","ReSoft","FhiSoft","VuaSoft","MSoft","NoSoft","PSoft","BSoft","JSoft","RiSoft","GaSoft","XSoft","SiiSoft","ISoft","WhSoft","KSoft","GSoft","RSoft","JudtSoft","RSoft","UmuSoft","MSoft","ASoft","CokSoft","ISoft","GaeSoft","FSoft","RSoft","WoSoft","FSoft","BektSoft","DSoft","TSoft","OrSoft","CaiiSoft","EuiSoft","ISoft","MutSoft","CSoft" };
char *company_names_ads[MAX_COMPANY_NAMES] = { "NeenfAds","PoAds","KeAds","OtAds","HiuoAds","MAds","BeiAds","LifteAds","YpiuqAds","MAds","XetmuAds","GhrAds","NuAds","FAds","WuccAds","NAds","GicmAds","FhAds","IokenAds","ChuiAds","VypbAds","SAds","SiguAds","FecijAds","SAds","NAds","FuAds","BAds","RupAds","BuAds","TAds","AuAds","TAds","KyrlAds","YAds","XAds","XeAds","CufmiAds","MirpAds","NoAds","JijnaAds","GovfaAds","NeapaAds","DAds","TujAds","XigiAds","YkAds","IsoAds","CombuAds","NiAds","GyAds","WuaddAds","DoAds","AwAds","DiAds","NiAds","VohAds","AmAds","GAds","GoAds","CoAds","TeAds","AjuzhAds","EAds","HAds","OAds","CisqoAds","QaflAds","UAds","MAds","CAds","AAds","ZAds","DAds","CigwAds","AfetAds","GAds","NAds","IAds","KyaiAds","RudoAds","FAds","XuyjwAds","OeAds","YAds","DAds","AlAds","LiwAds","KeAds","DiAds","LAds","KounAds","GuimAds","ColkAds","CeoAds","SAds","MeiiAds","EseboAds","FeAds","YdAds","CaAds","OAds","JhAds","AlAds","IejAds","PAds","MAds","LytbAds","FawlAds","PymgAds","CifgAds","HeAds","IeceAds","NoeAds","OkunbAds","MotbaAds","NikAds","RyoeAds","SoieAds","CAds","JAds","EAds","VirAds","PuAds","PAds","BiAds","FophAds","HeAds","BaAds","DAds","FaaeAds","PAds","DhsAds","PAds","EyAds","RybhoAds","OAds","PAds","JhbiAds","GAds","GAds","EveAds","DyolyAds","HuhAds","OmoeAds","UokAds","NaAds","JiiwbAds","WAds","PAds","MhluhAds","AsoqAds","RapAds","IhAds","OAds","BAds","HeojAds","EAds","GyxAds","QAds","LifAds","EAds","FivhiAds","AjovjAds","CoAds","ReAds","MynkaAds","QuqAds","KAds","AjihnAds","MepAds","ReuwAds","BAds","EAds","UpAds","QacAds","OAds","NoctAds","EAds","UyAds","KhjocAds","FyohAds","BipdAds","MeAds","IoavhAds","PudtAds","GuAds","NAds","LengAds","PAds","GAds","RAds","LAds","JiyxfAds","AajegAds","MAds","EasuAds","SyhuAds","CAds","UratvAds","GirnaAds","FetAds","PilghAds","ErAds","AAds","IdhAds","LeashAds","FajbaAds","RukeaAds","MAds","FecurAds","IbuAds","GAds","ByAds","LopAds","FAds","GotwuAds","MundiAds","XAds","MoAds","GooeuAds","AuihhAds","PonAds","OioAds","NAds","HedaiAds","IAds","BasniAds","PAds","OAds","OAds","ReckiAds","MAds","KAds","PAds","NivAds","BabAds","CarrAds","UAds","CauxeAds","NuemAds","TAds","RAds","SaAds","MopmAds","LAds","GapvAds","WiwAds","ObhbAds","MeeAds","AfaAds","ZabaxAds","GAds","SAds","GikfAds","LeaeAds","MunhyAds","UbAds","RAds","SAds","SaAds","LoAds","UAds","UlAds","AkeouAds","RAds","HAds","FuqqAds","UAds","SAds","YviAds","SokAds","JAds","SAds","MidpaAds","UyAds","RumpiAds","PAds","UAds","FokjuAds","FAds","UvonAds","VAds","KoAds","TAds","AriAds","QAds","WedbAds","RurmoAds","MAds","XAds","DioeAds","PeskAds","HAds","EAds","LAds","IgAds","OAds","LAds","KekAds","GAds","JedfuAds","PAds","CyAds","LaktAds","AAds","FedlAds","QAds","UeoAds","IAds","LiAds","OAds","GiokAds","JiwAds","OAds","QhmaAds","CeaiAds","LAds","EsaiAds","FAds","TaAds","DoxjoAds","CakAds","JufaAds","GaAds","RoAds","AnuwrAds","DotAds","QieeAds","EfhrAds","IobeAds","SAds","FaAds","GiAds","HuAds","NepbAds","OAds","KuwthAds","KefkhAds","JoAds","CAds","NAds","MojwiAds","CAds","XiAds","ApinpAds","FeAds","RAds","ChvuAds","DaAds","XiAds","EiigAds","UniAds","OAds","PuujAds","VekvaAds","WAds","YAds","SAds","FaftiAds","WeacjAds","UmoulAds","NAds","RufkhAds","GoAds","QAds","XanAds","JoAds","ZapniAds","DAds","MoAds","RelAds","OAds","JegAds","LudAds","DarAds","BajAds","GAds","TAds","OioguAds","MioobAds","FohqiAds","NiAds","NAds","NuAds","KiAds","ShAds","FAds","OpowvAds","TetbAds","TyirwAds","DahgAds","RAds","MiAds","UAds","DikAds","OuwonAds","PAds","ZAds","MhdAds","LenarAds","AeromAds","TAds","CepvaAds","HijAds","AapeAds","NAds","NAds","ZacqoAds","NixdeAds","ToanAds","BaAds","MAds","BanvAds","SunsyAds","NhAds","BodvAds","RAds","JabenAds","CoceAds","SAds","KAds","CAds","WAds","IbysAds","KiiolAds","YmiAds","LAds","KAds","JurAds","SuyegAds","TugAds","CibAds","JAds","UAds","EfikAds","EgAds","IAds","IiAds","DoeAds","RyvviAds","XawcAds","FAds","GaAds","OjohwAds","PemirAds","AAds","MujahAds","CamlhAds","UfhAds","NAds","TAds","DAds","MAds","WeAds","ReipkAds","TAds","KevAds","VugAds","XetbAds","YAds","EcuipAds","PAds","PAds","PaAds","PAds","CoAds","BunloAds","QolsAds","LAds","AAds","InAds","TofAds","GAds","UiaAds","AruAds","SouAds","ParAds","BopAds","MeuwAds","NhsayAds","CobtAds","JAds","CucluAds","GiAds","IsaAds","WigAds","PAds","RyaAds","AruvuAds","SAds","AAds","VohghAds","JofadAds","BudeaAds","HorAds","LaeAds","LuAds","IpAds","BaokAds","AAds","JiAds","TuAds","YdiydAds","EgiAds","TiriAds","BuAds","MAds","LuAds","GAds","RalviAds","JidAds","BAds","FAds","TAds","VyeAds","DAds","PuaogAds","JaAds","IAds","KAds","KAds","HisacAds","PAds","PaecAds","AaAds","TAds","ZAds","ZofAds","RAds","SukoAds","JAds","RAds","VyAds","DeAds","OfoAds","CAds","MAds","VAds","HesvAds","VAds","BAds","RedruAds","BogkAds","BauAds","EdibbAds","MAds","MyxsiAds","UsolAds","RiAds","SAds","ZoidrAds","JeonfAds","MAds","DAds","XolgAds","FaAds","DAds","TufgAds","OAds","OyworAds","TusAds","GAds","KAds","BelAds","GiyamAds","GhjAds","NoacsAds","EvieeAds","HAds","DeswAds","OAds","PoAds","NAds","SeohAds","KAds","SAds","TegAds","MeaAds","PoceaAds","RuhfeAds","VAds","SAds","BangiAds","LuleAds","KaAds","AnylAds","BAds","TAds","AAds","FuvAds","WhmiAds","OhuapAds","CAds","BidcAds","TuAds","KAds","AbysAds","SeruAds","PoebAds","NAds","MiAds","NhuAds","BoaAds","ImAds","VegnAds","SykAds","CAds","IwAds","DoitnAds","HagluAds","GAds","LAds","WAds","RihAds","VikAds","TaeAds","PaAds","AujacAds","ItimAds","LuhrAds","OjiAds","PelAds","HhAds","KaAds","UposAds","XuwuAds","IAds","BAds","IsusAds","SAds","PakiAds","ZovshAds","RuAds","BofhAds","PuoAds","JojbAds","IuuAds","CAds","GAds","GernAds","NAds","DarbiAds","PAds","TagnAds","YAds","OAds","GaaefAds","TAds","QauAds","KiAds","GhAds","LuiAds","AwoAds","RalgAds","DAds","IwepAds","KebfAds","ZAds","UnuAds","OtAds","NAds","DAds","CAds","DuhhAds","BakAds","MigdaAds","OAds","QhdeAds","BuoAds","MiAds","FyrAds","SAds","AqewgAds","KoAds","FonAds","WyoAds","SuAds","EjAds","BAds","AAds","EbyAds","EAds","TinkeAds","BAds","EfurdAds","UAds","PyAds","TAds","KAds","IAds","EAds","NAds","OiyAds","BigogAds","LopAds","AfuAds","XAds","SAds","TawAds","IrAds","TekfAds","GAds","PuqjAds","IAds","YgixgAds","SAds","PuAds","TaiesAds","ZuurAds","NAds","KongeAds","IAds","BAds","BAds","KiegAds","UdubAds","GiexlAds","OnioAds","CimAds","PovkeAds","BadquAds","VesnAds","MatmuAds","AzelAds","EAds","AAds","PaAds","CufAds","MAds","MAds","GifAds","FAds","UAds","ObhAds","DeAds","UjomAds","AAds","IAds","SikuAds","FhmogAds","DAds","EAds","OsAds","DexkaAds","KeAds","TeurtAds","ZAds","PAds","RinyeAds","VAds","IoAds","FuropAds","CowAds","MyisAds","GintaAds","GiAds","BAds","LAds","AsyAds","OenAds","AjaeAds","JudAds","EiAds","IAds","JAds","RevvAds","PyAds","KAds","PupAds","LAds","SiAds","FykAds","GoAds","EfyAds","RuwAds","OhanlAds","QAds","LAds","CAds","XAds","UAds","FAds","RAds","UxosiAds","WajgAds","OgumxAds","OaAds","RerAds","LAds","RAds","CAds","LeAds","AAds","EsoAds","YhuriAds","BAds","FuAds","OAds","FuAds","GifAds","LihsiAds","FeAds","UAds","JirAds","ElAds","AguAds","GijtoAds","AtyAds","RuguAds","KaAds","HAds","OAds","PouAds","ImoAds","TAds","KeAds","SaAds","LuiicAds","FAds","LAds","TAds","RAds","EfiwAds","QelvAds","NAds","LAds","EnoAds","MAds","IchbuAds","BocAds","CicfhAds","XifAds","BosevAds","KonzeAds","NAds","QalaAds","OlidsAds","DokseAds","VazAds","AnAds","HagAds","OAds","IAds","FuabcAds","FAds","ErAds","PoaljAds","MoftAds","RuAds","TAds","DoloAds","VAds","UAds","YnoonAds","RAds","MixduAds","PhlAds","SuAds","KhAds","FadbAds","MAds","LuyucAds","GAds","LessyAds","EpieAds","BieeAds","KAds","VeobAds","GefAds","SAds","WumAds","DooAds","XumwaAds","IgukAds","PAds","WilsuAds","NAds","DAds","RAds","MeqpAds","NuAds","YuoAds","ByjhuAds","JaAds","GieluAds","MoknyAds","ToAds","VesAds","KoroAds","VAds","JihtoAds","NonfAds","CifkeAds","JogdoAds","JigmaAds","TikpeAds","AojeqAds","SAds","NipnaAds","KAds","HiajAds","FAds","RAds","UanocAds","PaceAds","LavivAds","WAds","JAds","TuAds","TiAds","MAds","OdoAds","RuAds","UAds","BAds","FAds","DaAds","EAds","DiAds","BAds","KAds","PAds","IAds","EocoAds","QusziAds","UAds","UbirAds","BicAds","WuunAds","LiAds","WejsAds","BoAds","HAds","UtoAds","GeAds","OkeAds","LaAds","GerneAds","AijAds","SAds","TafaAds","EsuAds","TeAds","DAds","SaejdAds","WoAds","WamtAds","AAds","LomikAds","GoulAds","TAds","JemfAds","TaubeAds","BoytxAds","YhoAds","VhsuAds","AysoAds","WecnoAds","GirAds","MAds","FeAds","DAds","SAds","FemAds","EehAds","ExorAds","RipAds","GuwfAds","JejiAds","JuoicAds","SuaAds","DotlAds","WijAds","CAds","NodAds","FounAds","AkAds","UAds","ArAds","NAds","DoAds","GuufaAds","OlaAds","OAds","BapfiAds","HaggaAds","PAds","TiAds","FenAds","HiatAds","RedAds","JAds","DAds","SAds","CyjAds","KezfAds","KifAds","QAds","FaduyAds" };
char *company_names_drugs[MAX_COMPANY_NAMES] = { "PLab","CLab","GyiLab","ELab","SepwhLab","TLab","FLab","EomLab","OicuLab","JLab","ULab","KuLab","SLab","ELab","TiaLab","BLab","CoxLab","KLab","SLab","DeLab","JyfmLab","NLab","MLab","MLab","TLab","VLab","RoLab","LifchLab","SurkLab","GLab","LLab","TeqoLab","JLab","XaLab","ELab","GeoLab","DhikLab","ULab","RLab","TyvLab","GumgLab","KexyLab","WyibtLab","FLab","MatLab","AciLab","GokaLab","SiljuLab","MubwuLab","ULab","ViuclLab","NLab","EkhgLab","UwLab","CLab","LLab","FojLab","OLab","JorLab","EjaLab","HokeLab","ToLab","LuLab","KetiLab","GuocmLab","KyvdLab","JoLab","SaLab","WuwlhLab","AkaodLab","JaiLab","JuLab","OazetLab","ZiLab","JLab","MoLab","SLab","FocuLab","CeukrLab","RotLab","AqefLab","PovLab","LyueLab","JLab","AhidfLab","ALab","VLab","SLab","PLab","AfazkLab","VexLab","HLab","RoparLab","PLab","DyugLab","ILab","TyLab","EmeLab","ChLab","LouaLab","OgokLab","KeejLab","OdedLab","ReuLab","GadLab","FoLab","GLab","KodLab","ZucLab","ELab","NelheLab","UsekaLab","GuteyLab","IfitrLab","MLab","ALab","ULab","BigiLab","MupluLab","SoneLab","DomLab","BaLab","LLab","OLab","HenvLab","MorpLab","PinrLab","XLab","JuLab","RhlonLab","MLab","MimjLab","BLab","FLab","JihLab","LevLab","SLab","PhenyLab","OjopLab","ULab","ZLab","VhyeLab","TuLab","NabLab","WeoicLab","EdaeLab","EgLab","GoiaLab","SLab","ZoLab","UgaLab","MauqLab","RuikbLab","EhaiLab","SeyqvLab","DLab","SahneLab","RuxtoLab","PLab","EmyLab","FijLab","BLab","RLab","TLab","PLab","TiyLab","VLab","IjipLab","CLab","OLab","OaqaLab","KorkiLab","FaLab","ALab","OuLab","RisphLab","FidLab","PitLab","SenLab","ELab","HugkaLab","IwugLab","BagliLab","JuLab","FyrLab","IiLab","BLab","AkulsLab","QedLab","JLab","UaLab","BehaLab","ZLab","NLab","JhsiaLab","OciLab","ALab","WLab","KLab","GLab","RuatLab","PekmaLab","KeLab","TedLab","JuLab","WLab","NLab","CojhLab","KiifkLab","DyLab","PaLab","ALab","FowLab","PuLab","HomLab","MieLab","YLab","LLab","RieLab","IaeLab","TiefLab","OenueLab","ExLab","SLab","TLab","GazgaLab","GLab","BLab","QLab","FoLab","VLab","DLab","OkaLab","UheLab","ZushoLab","CLab","VLab","LaauLab","PujimLab","BijpoLab","EwihrLab","DuurmLab","AjakLab","YeeiLab","SosxLab","YnaaoLab","OmLab","PiodLab","RihkLab","NiybrLab","UmoLab","ChdLab","UdLab","XyukoLab","AvacdLab","SLab","IiceiLab","VLab","MoqLab","OLab","VLab","RegtoLab","KLab","RakuLab","MaiLab","ALab","DLab","VeLab","MLab","MLab","TuLab","UosLab","SyxsuLab","BebziLab","LLab","WaLab","KhoLab","XiLab","SeedLab","JidLab","SLab","ULab","QafwuLab","NLab","NivfLab","OLab","FLab","BugonLab","JonLab","BLab","MouLab","KLab","BoLab","IrebeLab","MevLab","SLab","FuworLab","HLab","CiLab","HodjLab","BLab","AnalfLab","SeeybLab","UdossLab","XeninLab","GohatLab","ReraLab","AfevLab","HaLab","PaLab","WiLab","OLab","RyLab","JawiLab","GisveLab","YcLab","CLab","VLab","DLab","HuqsiLab","MLab","BLab","MafsaLab","BileLab","SyjbLab","DLab","LLab","CoiuLab","CyLab","FedwLab","PifliLab","CujfoLab","MitLab","ULab","PabiLab","BodciLab","EuLab","JibwLab","ALab","TLab","XhLab","KiwjuLab","TazpuLab","QhiLab","SadmaLab","SepLab","MLab","MeLab","PoLab","QLab","DLab","MLab","VuLab","SaeLab","QoiLab","CLab","AkaaLab","BelLab","VirLab","ELab","HotLab","FusLab","RaLab","AeLab","IieezLab","BivtLab","JLab","WLab","KofygLab","NoLab","GiydfLab","TLab","OLab","NLab","ItubhLab","PoblLab","ELab","BLab","TLab","RLab","KaLab","MLab","RoupoLab","DectLab","GuuiLab","EeriLab","CutpLab","WotLab","RajLab","CucsLab","NeLab","SolfoLab","LyLab","UuLab","CLab","FoLab","MeibvLab","SisLab","FipLab","VavLab","DLab","DouwLab","KyiLab","GuLab","FiqjLab","EbaLab","ToswLab","IpitnLab","KLab","WaLab","HyfzLab","CykLab","HedLab","PeklLab","BLab","ZLab","LLab","HanwLab","NisdeLab","OofLab","DoLab","WiLab","ExarLab","ALab","GobLab","LLab","ELab","GioxeLab","OuexLab","HLab","NagaLab","CemLab","KeferLab","DLab","UlesoLab","CemLab","DLab","ZeurLab","FhnaLab","SepoLab","HLab","OtLab","JLab","SavguLab","BepchLab","NLab","KohLab","EhLab","BywfeLab","LajLab","HLab","WLab","ALab","RLab","JenLab","ToLab","WadtuLab","MitLab","JiLab","PiLab","PiLab","RLab","JLab","AaoLab","UtagLab","ULab","MuLab","WLab","ZLab","SoqeLab","DLab","AzosLab","OseLab","TiiLab","EcyjLab","TeLab","DorLab","MLab","ApiLab","LepoiLab","RosLab","GLab","AsLab","ALab","RhefeLab","SoudLab","SLab","UkaeLab","QeulfLab","LumpLab","AlobLab","OLab","DaawLab","ToiLab","JLab","HLab","DocLab","VLab","ViijdLab","BLab","YodLab","AywamLab","NanfuLab","MiiLab","BoLab","CLab","LowlLab","FoveuLab","NLab","SLab","HasqhLab","WekLab","CatLab","LaLab","NLab","CafnLab","KylLab","GhLab","TyineLab","BumLab","ZLab","SeLab","ShhacLab","IkLab","SLab","NiaxLab","OcLab","RyLab","OLab","OLab","ULab","BLab","DLab","QocvLab","LLab","JodLab","YLab","KebLab","MetLab","AniLab","NudijLab","ULab","FoyLab","LuaxLab","ULab","VuLab","CLab","EpLab","WLab","PLab","MaggLab","LiLab","UqifLab","ThuLab","JudsLab","LicvLab","LLab","LLab","SobLab","IgLab","RaLab","TobduLab","SiLab","LavLab","VLab","GiLab","ChthfLab","VhghLab","PaLab","TLab","EjuspLab","XLab","RaibjLab","BLab","AbutdLab","KLab","JeusnLab","NokiLab","CueLab","JoadLab","SijgiLab","PerbiLab","ZiLab","GivLab","MLab","GyomLab","WLab","BLab","BoooqLab","AmLab","EfyLab","TiLab","RLab","MidLab","UrumLab","VodwaLab","OekyLab","HugmiLab","GujLab","WaofLab","NLab","LoepLab","IfaLab","TonomLab","ULab","MuruLab","MabgeLab","KLab","DawshLab","PLab","IrLab","VevLab","WLab","VLab","LLab","DekpuLab","RujmLab","OgLab","YLab","KLab","ULab","BLab","KudgLab","VodniLab","HoshiLab","DLab","RavLab","EteseLab","LitgeLab","FubveLab","BihcLab","VehLab","DerLab","GanubLab","KLab","MLab","PLab","DabhLab","CLab","DindLab","QiqkiLab","UwaygLab","UduLab","IuLab","HofLab","TLab","KohqLab","PeubbLab","ALab","WLab","PLab","XLab","SLab","ZoiLab","LLab","TaznLab","YLab","RopsLab","CeLab","QaLab","RLab","PLab","MifLab","InenLab","KoifLab","ImoocLab","FLab","SeLab","MLab","GoLab","AuguhLab","DagLab","FimlaLab","SilaLab","EboLab","OLab","PyLab","RovLab","PLab","OLab","LLab","AfaLab","SypLab","DLab","WatqiLab","KuLab","BoLab","FudkaLab","NujLab","CeLab","KaLab","HyLab","LifdLab","UkauoLab","HelwiLab","UaLab","VekcyLab","FyLab","AxemLab","YfLab","RieLab","MLab","RekbaLab","CLab","NLab","RaepLab","UkLab","NosmiLab","NLab","BotLab","LoypdLab","KouunLab","KLab","XuLab","OlLab","LiuLab","SymsLab","YLab","LLab","LhLab","GiadLab","PLab","LocmLab","SubfLab","NLab","ELab","FLab","ELab","DLab","SivLab","CuLab","DLab","NLab","GejLab","IafiuLab","OLab","WLab","OrLab","HLab","NimLab","HoayLab","MuikLab","MLab","KaLab","JeruLab","NeruwLab","OLab","NeljLab","ToLab","UobauLab","KuosnLab","UsiebLab","GucjiLab","KadrLab","OLab","QounLab","RLab","FilymLab","KouLab","FiLab","NueLab","QimLab","CosLab","TeLab","DLab","WetkuLab","YLab","ILab","BecryLab","IvhufLab","PLab","QLab","SaolLab","QulmLab","BiddLab","TigunLab","OLab","SatlLab","FeaeLab","SLab","ILab","ALab","UlobLab","NLab","MiowiLab","JobLab","CeuiLab","OcouLab","MLab","SoLab","VowvaLab","NuLab","JewLab","ItocgLab","ToziLab","SaLab","TLab","JLab","ILab","NhLab","ALab","HedlLab","AzizpLab","KhLab","RaLab","FLab","GefLab","PLab","RuqdoLab","EeLab","XesqLab","LLab","ItLab","WhteaLab","DijjyLab","XLab","UefiLab","ELab","KumLab","MoLab","SLab","RLab","JerLab","AnLab","OjaLab","HopLab","DoidLab","NioteLab","OodiLab","VaLab","OxonLab","XioLab","AlLab","RLab","DeLab","JoLab","DLab","QiLab","GuolLab","ILab","KaLab","MLab","GupLab","JoeLab","IwujpLab","TaLab","GLab","HLab","ALab","DulLab","NufLab","HuwwhLab","EevicLab","UkeLab","CipfeLab","MLab","IqeLab","OLab","XLab","BLab","NugbLab","GicwoLab","ShLab","TunLab","NegLab","ZijLab","FLab","FLab","MuLab","KLab","MLab","GLab","KicbiLab","MhlodLab","FLab","JuyvLab","TagiLab","RLab","NoelbLab","CLab","FofmLab","PijlyLab","LyLab","LyeLab","KLab","IaamLab","OcLab","MuxmaLab","VLab","ZLab","BufjoLab","MLab","QorjLab","ShsuLab","NeLab","CLab","ReLab","IimLab","RhfhLab","SakaeLab","MhlunLab","TeiLab","NeLab","OiLab","AreLab","NLab","MLab","HLab","BaLab","OtojlLab","IuLab","NitLab","ZeLab","LobLab","RoccLab","GieLab","GhrLab","ChewLab","ReblLab","OoLab","FudvLab","JouLab","UhiafLab","DonLab","KeLab","BuLab","KijrLab","BLab","SLab","RyekqLab","TLab","SatmLab","SikopLab","FLab","BijbyLab","GLab","RoLab","VhjeyLab","LyjzLab","EjowsLab","SotqeLab","OLab","RufdyLab","KLab","JaLab","RixLab","CijrLab","NopLab","SeLab","PLab","PipmLab","JuidaLab","FigLab","JehrLab","QebcLab","XLab","AbipLab","WygneLab","SLab","QinLab","KLab","EjoocLab","FaLab","BeLab","ApatLab","PuhdoLab","IlugaLab","TLab","KunaLab","TLab","FuLab","DLab","OLab","HorarLab","ILab","LutfaLab","LeLab","PLab","PLab","LiLab","RimLab","DegnLab","FLab","SeoLab","CubraLab","HoefLab","ULab","ZumLab","GicLab","HLab","PLab","ELab","DorLab","AgLab","ReifLab","HLab","DoLab","RLab","HuLab","SovjLab" };

char *companies_get_name(char *names[], int type_idx) {
  static int used_names[4][MAX_COMPANY_NAMES];
  int lookup_name = 1, r;
  do {
    r = helper_random_int_min_max(0, 1000);
    if (used_names[type_idx][r] != 1) {
      used_names[type_idx][r] = 1;
      return names[r];
      lookup_name = 0;
    }
  } while (lookup_name == 1);
  return NULL;
}

void companies_init(void) {
  int i, j, r;

  for (i = 0; i < MAX_COMPANIES; i++) {
    companies[i].id = i;
    r = helper_random_int_min_max(0, 4);
    switch (r) {
      case 0:
        companies[i].type = COMPANY_TYPE_HARDWARE;
        companies[i].sub_types[0].type = COMPANY_SUB_TYPE_HARDWARE_NET;
        companies[i].sub_types[1].type = COMPANY_SUB_TYPE_HARDWARE_COM;
        companies[i].sub_types[2].type = COMPANY_SUB_TYPE_HARDWARE_SAT;
        companies[i].name = companies_get_name(company_names_hardware, r);
        break;
      case 1:
        companies[i].type = COMPANY_TYPE_SOFTWARE;
        companies[i].sub_types[0].type = COMPANY_SUB_TYPE_SOFTWARE_SCI;
        companies[i].sub_types[1].type = COMPANY_SUB_TYPE_SOFTWARE_SEC;
        companies[i].sub_types[2].type = COMPANY_SUB_TYPE_SOFTWARE_PRD;
        companies[i].name = companies_get_name(company_names_software, r);
        break;
      case 2:
        companies[i].type = COMPANY_TYPE_ADS;
        companies[i].sub_types[0].type = COMPANY_SUB_TYPE_ADS_ACO;
        companies[i].sub_types[1].type = COMPANY_SUB_TYPE_ADS_VIS;
        companies[i].sub_types[2].type = COMPANY_SUB_TYPE_ADS_THO;
        companies[i].name = companies_get_name(company_names_ads, r);
        break;
      case 3:
        companies[i].type = COMPANY_TYPE_DRUGS;
        companies[i].sub_types[0].type = COMPANY_SUB_TYPE_DRUGS_MOO;
        companies[i].sub_types[1].type = COMPANY_SUB_TYPE_DRUGS_HAL;
        companies[i].sub_types[2].type = COMPANY_SUB_TYPE_DRUGS_AHA;
        companies[i].name = companies_get_name(company_names_drugs, r);
        break;
    }
    companies[i].last_rank = -1;
    companies[i].strength = 0.0;
    for (j = 0; j < 3; j++) {
      companies[i].sub_types[j].strength = helper_random_float_min_max(0.0, 10.0);
      companies[i].strength += companies[i].sub_types[j].strength;
    }
  }

  companies_sort();
}

void companies_recalculate(void) {
  int i, j;
  for (i = 0; i < MAX_COMPANIES; i++) {
    companies[i].last_rank = i;
    if (helper_random_probability(0.25) == 1) {
      // 1/4 probability to change strength
      companies[i].strength = 0;
      for (j = 0; j < 3; j++) {
        if (helper_random_probability(0.333) == 1) {
          // 1/3 probability to change a single strength
          if (helper_random_probability(0.5) == 1) {
            // 1/2 probability to change a strength up
            companies[i].sub_types[j].strength = helper_random_float_min_max(
              companies[i].sub_types[j].strength, 10.0
            );
          } else {
            // 1/2 probability to change a strength down
            companies[i].sub_types[j].strength = helper_random_float_min_max(
              0.0, companies[i].sub_types[j].strength
            );
          }
        }
        companies[i].strength += companies[i].sub_types[j].strength;
      }
    }

  }
  companies_sort();
}

void companies_sort(void) {
  int i, has_change = 0;
  struct company tmp_company;

  for (i = 0; i < MAX_COMPANIES - 1; i++) {
    if (companies[i].strength < companies[i+1].strength) {
      has_change = 1;

      tmp_company = companies[i];
      companies[i] = companies[i+1];
      companies[i+1] = tmp_company;
    }
  }
  if (has_change == 1) companies_sort();
}

void companies_get_type_str(char *type_str, int type) {
  switch (type) {
    case COMPANY_TYPE_HARDWARE:
      snprintf(type_str, 128, "Hardware");
      break;
    case COMPANY_TYPE_SOFTWARE:
      snprintf(type_str, 128, "Software");
      break;
    case COMPANY_TYPE_ADS:
      snprintf(type_str, 128, "Ads");
      break;
    case COMPANY_TYPE_DRUGS:
      snprintf(type_str, 128, "Drugs");
      break;
  }
}

void companies_get_sub_type_str(char *sub_type_str, int sub_type) {
  switch (sub_type) {
    case COMPANY_SUB_TYPE_HARDWARE_NET:
      snprintf(sub_type_str, 128, "NET");
      break;
    case COMPANY_SUB_TYPE_HARDWARE_COM:
      snprintf(sub_type_str, 128, "COM");
      break;
    case COMPANY_SUB_TYPE_HARDWARE_SAT:
      snprintf(sub_type_str, 128, "SAT");
      break;
    case COMPANY_SUB_TYPE_SOFTWARE_SCI:
      snprintf(sub_type_str, 128, "SCI");
      break;
    case COMPANY_SUB_TYPE_SOFTWARE_SEC:
      snprintf(sub_type_str, 128, "SEC");
      break;
    case COMPANY_SUB_TYPE_SOFTWARE_PRD:
      snprintf(sub_type_str, 128, "PRD");
      break;
    case COMPANY_SUB_TYPE_ADS_ACO:
      snprintf(sub_type_str, 128, "ACO");
      break;
    case COMPANY_SUB_TYPE_ADS_VIS:
      snprintf(sub_type_str, 128, "VIS");
      break;
    case COMPANY_SUB_TYPE_ADS_THO:
      snprintf(sub_type_str, 128, "THO");
      break;
    case COMPANY_SUB_TYPE_DRUGS_MOO:
      snprintf(sub_type_str, 128, "MOO");
      break;
    case COMPANY_SUB_TYPE_DRUGS_HAL:
      snprintf(sub_type_str, 128, "HAL");
      break;
    case COMPANY_SUB_TYPE_DRUGS_AHA:
      snprintf(sub_type_str, 128, "AHA");
      break;
  }
}

char *companies_get_top5(int type) {
  static char str[1024];
  char ch_str[512], type_str[128];
  int i = 0, k = 0, j;

  companies_get_type_str(type_str, type);
  snprintf(str, 1024, "Top 5 Companies [%s]:\n", type_str);
  while (k < 5) {
    if (companies[i].type == type) {
      snprintf(ch_str, 512, "%d. ", i+1);
      strcat(str, ch_str);
      strcat(str, companies[i].name);
      strcat(str, " ");

      if (companies[i].last_rank == -1) {
        strcat(str, "(new)");
      } else {
        snprintf(ch_str, 512, "(%d)", companies[i].last_rank - i);
        strcat(str, ch_str);
      }
      strcat(str, "\n|-- ");

      for (j = 0; j < 3; j++) {
        if (j > 0)
          strcat(str, "-- ");

        companies_get_sub_type_str(type_str, companies[i].sub_types[j].type);
        snprintf(
          ch_str, 512, "%s = %.2f ",
          type_str, companies[i].sub_types[j].strength
        );
        strcat(str, ch_str);
      }
      strcat(str, "\n");
      k++;
    }
    i++;
  }
  strcat(str, "\n");
  return str;
}