/***************************************************************************\
* Module Name: KBDGR.C
*
* keyboard layout for German
*
* Copyright (c) 1985-2000, Microsoft Corporation
*
\***************************************************************************/

#include <windows.h>
#include "kbd.h"
#include "kbdjpn.h"
#include "kbd101gr.h"
#include "kbdGR.h"

#if defined(_M_IA64)
#pragma section(".data")
#define ALLOC_SECTION_LDATA __declspec(allocate(".data"))
#else
#pragma data_seg(".data")
#define ALLOC_SECTION_LDATA
#endif

/***************************************************************************\
* ausVK[] - Virtual Scan Code to Virtual Key conversion table for German
\***************************************************************************/

static ALLOC_SECTION_LDATA USHORT ausVK[] = {
	T00, T01, T02, T03, T04, T05, T06, T07,
	T08, T09, T0A, T0B, T0C, T0D, T0E, T0F,
	T10, T11, T12, T13, T14, T15, T16, T17,
	T18, T19, T1A, T1B, T1C, T1D, T1E, T1F,
	T20, T21, T22, T23, T24, T25, T26, T27,
	T28,

	/*
	* '^' key must have KBDSPECIAL bit set. (NLS key)
	*/
	T29 | KBDSPECIAL,

	T2A, T2B, T2C, T2D, T2E, T2F,
	T30, T31, T32, T33, T34, T35,

	/*
	* Right-hand Shift key must have KBDEXT bit set.
	*/
	T36 | KBDEXT,

	T37 | KBDMULTIVK,               // numpad_* + Shift/Alt -> SnapShot

	T38, T39,

	/*
	* CapsLock key must have KBDSPECIAL bit set. (NLS key)
	*/
	T3A | KBDSPECIAL,

	T3B, T3C, T3D, T3E,
	T3F, T40, T41, T42, T43, T44,

	/*
	* NumLock Key:
	*     KBDEXT     - VK_NUMLOCK is an Extended key
	*     KBDMULTIVK - VK_NUMLOCK or VK_PAUSE (without or with CTRL)
	*/
	T45 | KBDEXT | KBDMULTIVK,

	T46 | KBDMULTIVK,

	/*
	* Number Pad keys:
	*     KBDNUMPAD  - digits 0-9 and decimal point.
	*     KBDSPECIAL - require special processing by Windows
	*/
	T47 | KBDNUMPAD | KBDSPECIAL,   // Numpad 7 (Home)
	T48 | KBDNUMPAD | KBDSPECIAL,   // Numpad 8 (Up),
	T49 | KBDNUMPAD | KBDSPECIAL,   // Numpad 9 (PgUp),
	T4A,
	T4B | KBDNUMPAD | KBDSPECIAL,   // Numpad 4 (Left),
	T4C | KBDNUMPAD | KBDSPECIAL,   // Numpad 5 (Clear),
	T4D | KBDNUMPAD | KBDSPECIAL,   // Numpad 6 (Right),
	T4E,
	T4F | KBDNUMPAD | KBDSPECIAL,   // Numpad 1 (End),
	T50 | KBDNUMPAD | KBDSPECIAL,   // Numpad 2 (Down),
	T51 | KBDNUMPAD | KBDSPECIAL,   // Numpad 3 (PgDn),
	T52 | KBDNUMPAD | KBDSPECIAL,   // Numpad 0 (Ins),
	T53 | KBDNUMPAD | KBDSPECIAL,   // Numpad . (Del),

	T54, T55, T56, T57, T58, T59, T5A, T5B,
	T5C, T5D, T5E, T5F, T60, T61, T62, T63,
	T64, T65, T66, T67, T68, T69, T6A, T6B,
	T6C, T6D, T6E, T6F, T70, T71, T72, T73,
	T74, T75, T76, T77, T78, T79, T7A, T7B,
	T7C, T7D, T7E

};

static ALLOC_SECTION_LDATA VSC_VK aE0VscToVk[] = {
	{ 0x10, X10 | KBDEXT },  // Speedracer: Previous Track
	{ 0x19, X19 | KBDEXT },  // Speedracer: Next Track
	{ 0x1D, X1D | KBDEXT },  // RControl
	{ 0x20, X20 | KBDEXT },  // Speedracer: Volume Mute
	{ 0x21, X21 | KBDEXT },  // Speedracer: Launch App 2
	{ 0x22, X22 | KBDEXT },  // Speedracer: Media Play/Pause
	{ 0x24, X24 | KBDEXT },  // Speedracer: Media Stop
	{ 0x2E, X2E | KBDEXT },  // Speedracer: Volume Down
	{ 0x30, X30 | KBDEXT },  // Speedracer: Volume Up
	{ 0x32, X32 | KBDEXT },  // Speedracer: Browser Home
	{ 0x35, X35 | KBDEXT },  // Numpad Divide
	{ 0x37, X37 | KBDEXT },  // Snapshot
	{ 0x38, X38 | KBDEXT },  // RMenu
	{ 0x47, X47 | KBDEXT },  // Home
	{ 0x48, X48 | KBDEXT },  // Up
	{ 0x49, X49 | KBDEXT },  // Prior
	{ 0x4B, X4B | KBDEXT },  // Left
	{ 0x4D, X4D | KBDEXT },  // Right
	{ 0x4F, X4F | KBDEXT },  // End
	{ 0x50, X50 | KBDEXT },  // Down
	{ 0x51, X51 | KBDEXT },  // Next
	{ 0x52, X52 | KBDEXT },  // Insert
	{ 0x53, X53 | KBDEXT },  // Delete
	{ 0x5B, X5B | KBDEXT },  // Left Win
	{ 0x5C, X5C | KBDEXT },  // Right Win
	{ 0x5D, X5D | KBDEXT },  // Application
	{ 0x5F, X5F | KBDEXT },  // Speedracer: Sleep
	{ 0x65, X65 | KBDEXT },  // Speedracer: Browser Search
	{ 0x66, X66 | KBDEXT },  // Speedracer: Browser Favorites
	{ 0x67, X67 | KBDEXT },  // Speedracer: Browser Refresh
	{ 0x68, X68 | KBDEXT },  // Speedracer: Browser Stop
	{ 0x69, X69 | KBDEXT },  // Speedracer: Browser Forward
	{ 0x6A, X6A | KBDEXT },  // Speedracer: Browser Back
	{ 0x6B, X6B | KBDEXT },  // Speedracer: Launch App 1
	{ 0x6C, X6C | KBDEXT },  // Speedracer: Launch Mail
	{ 0x6D, X6D | KBDEXT },  // Speedracer: Launch Media Selector
	{ 0x1C, X1C | KBDEXT },  // Numpad Enter
	{ 0x46, X46 | KBDEXT },  // Break (Ctrl + Pause)
	{ 0,      0 }
};

static ALLOC_SECTION_LDATA VSC_VK aE1VscToVk[] = {
	{ 0x1D, Y1D },  // Pause
	{ 0   ,   0 }
};

/***************************************************************************\
* aVkToBits[]  - map Virtual Keys to Modifier Bits
*
* See kbd.h for a full description.
*
* German Keyboard has only three shifter keys:
*     SHIFT (L & R) affects alphabnumeric keys,
*     CTRL  (L & R) is used to generate control characters
*     ALT   (L & R) used for generating characters by number with numpad
\***************************************************************************/
static ALLOC_SECTION_LDATA VK_TO_BIT aVkToBits[] = {
	{ VK_SHIFT    ,   KBDSHIFT },
	{ VK_CONTROL  ,   KBDCTRL },
	{ VK_MENU     ,   KBDALT },
	{ VK_KANA     ,   KBDKANA },
	{ 0           ,   0 }
};

/***************************************************************************\
* aModification[]  - map character modifier bits to modification number
*
* See kbd.h for a full description.
*
\***************************************************************************/


static ALLOC_SECTION_LDATA MODIFIERS CharModifiers = {
	&aVkToBits[0],
	11,
	{
		//  Modification# //  Keys Pressed 
		//  ============= // =============
		0,            // 
		1,            // Shift 
		5,            // Control 
		7,            // Shift + Control 
		SHFT_INVALID, // Menu 
		SHFT_INVALID, // Shift + Menu 
		4,            // Control + Menu 
		SHFT_INVALID, // Shift + Control + Menu 
		2,            // Kana 
		3,            // Shift + Kana 
		6,            // Control + Kana 
		8             // Shift + Control + Kana
	}
};

/***************************************************************************\
*
* aVkToWch2[]  - Virtual Key to WCHAR translation for 2 shift states
* aVkToWch3[]  - Virtual Key to WCHAR translation for 3 shift states
* aVkToWch4[]  - Virtual Key to WCHAR translation for 4 shift states
* aVkToWch5[]  - Virtual Key to WCHAR translation for 5 shift states
*
* Table attributes: Unordered Scan, null-terminated
*
* Search this table for an entry with a matching Virtual Key to find the
* corresponding unshifted and shifted WCHAR characters.
*
* Special values for VirtualKey (column 1)
*     0xff          - dead chars for the previous entry
*     0             - terminate the list
*
* Special values for Attributes (column 2)
*     CAPLOK bit    - CAPS-LOCK affect this key like SHIFT
*     KANALOK bit   - The KANA-LOCK key affects this key like KANA
*
* Special values for wch[*] (column 3 & 4)
*     WCH_NONE      - No character
*     WCH_DEAD      - Dead Key (diaresis) or invalid (US keyboard has none)
*     WCH_LGTR      - Ligature (generates multiple characters)
*
\***************************************************************************/

static ALLOC_SECTION_LDATA VK_TO_WCHARS4 aVkToWch4[] = {
	//                                |         |  Shift  |  KANA  | K+SHFT |
	//                                |=========|=========|========|========|
	// dead keys not supported with Japanese input
	// { VK_OEM_5     ,         KANALOK ,WCH_DEAD ,0x00b0   ,WCH_RO  ,WCH_RO },
	// { 0xff         ,0                ,'^'      ,WCH_NONE ,WCH_NONE,WCH_NONE },
	{ VK_OEM_5     ,         KANALOK ,'^'      ,0x00b0   ,WCH_RO  ,WCH_RO },
	{ '1'          ,         KANALOK ,'1'      ,'!'      ,WCH_NU  ,WCH_NU },
	{ '4'          ,         KANALOK ,'4'      ,'$'      ,WCH_U   ,WCH_UU },
	{ '5'          ,         KANALOK ,'5'      ,'%'      ,WCH_E   ,WCH_EE },
	// dead keys not supported with Japanese input
	// { VK_OEM_6     ,         KANALOK ,WCH_DEAD ,WCH_DEAD ,WCH_HE  ,WCH_HE },
	// { 0xff         ,0                ,0x00b4   ,'`'      ,WCH_NONE,WCH_NONE },
	{ VK_OEM_6     ,         KANALOK ,0x00b4   ,'`'      ,WCH_HE  ,WCH_HE },
	{ 'W'          ,CAPLOK | KANALOK ,'w'      ,'W'      ,WCH_TE  ,WCH_TE },
	{ 'R'          ,CAPLOK | KANALOK ,'r'      ,'R'      ,WCH_SU  ,WCH_SU },
	{ 'T'          ,CAPLOK | KANALOK ,'t'      ,'T'      ,WCH_KA  ,WCH_KA },
	{ 'Z'          ,CAPLOK | KANALOK ,'z'      ,'Z'      ,WCH_NN  ,WCH_NN },
	{ 'U'          ,CAPLOK | KANALOK ,'u'      ,'U'      ,WCH_NA  ,WCH_NA },
	{ 'I'          ,CAPLOK | KANALOK ,'i'      ,'I'      ,WCH_NI  ,WCH_NI },
	{ 'O'          ,CAPLOK | KANALOK ,'o'      ,'O'      ,WCH_RA  ,WCH_RA },
	{ 'P'          ,CAPLOK | KANALOK ,'p'      ,'P'      ,WCH_SE  ,WCH_SE },
	{ 'A'          ,CAPLOK | KANALOK ,'a'      ,'A'      ,WCH_TI  ,WCH_TI },
	{ 'S'          ,CAPLOK | KANALOK ,'s'      ,'S'      ,WCH_TO  ,WCH_TO },
	{ 'D'          ,CAPLOK | KANALOK ,'d'      ,'D'      ,WCH_SI  ,WCH_SI },
	{ 'F'          ,CAPLOK | KANALOK ,'f'      ,'F'      ,WCH_HA  ,WCH_HA },
	{ 'G'          ,CAPLOK | KANALOK ,'g'      ,'G'      ,WCH_KI  ,WCH_KI },
	{ 'H'          ,CAPLOK | KANALOK ,'h'      ,'H'      ,WCH_KU  ,WCH_KU },
	{ 'J'          ,CAPLOK | KANALOK ,'j'      ,'J'      ,WCH_MA  ,WCH_MA },
	{ 'K'          ,CAPLOK | KANALOK ,'k'      ,'K'      ,WCH_NO  ,WCH_NO },
	{ 'L'          ,CAPLOK | KANALOK ,'l'      ,'L'      ,WCH_RI  ,WCH_RI },
	{ VK_OEM_3     ,         KANALOK ,0x00f6   ,0x00d6   ,WCH_RE  ,WCH_RE },
	{ VK_OEM_7     ,         KANALOK ,0x00e4   ,0x00c4   ,WCH_KE  ,WCH_KE },
	{ 'X'          ,CAPLOK | KANALOK ,'x'      ,'X'      ,WCH_SA  ,WCH_SA },
	{ 'C'          ,CAPLOK | KANALOK ,'c'      ,'C'      ,WCH_SO  ,WCH_SO },
	{ 'V'          ,CAPLOK | KANALOK ,'v'      ,'V'      ,WCH_HI  ,WCH_HI },
	{ 'B'          ,CAPLOK | KANALOK ,'b'      ,'B'      ,WCH_KO  ,WCH_KO },
	{ 'N'          ,CAPLOK | KANALOK ,'n'      ,'N'      ,WCH_MI  ,WCH_MI },
	{ VK_OEM_COMMA ,         KANALOK ,','      ,';'      ,WCH_NE  ,WCH_IC },
	{ VK_OEM_PERIOD,         KANALOK ,'.'      ,':'      ,WCH_RU  ,WCH_IP },
	{ VK_DECIMAL   ,0                ,','      ,','      ,','      ,',' },
	{ VK_TAB       ,0                ,'\t'     ,'\t'     ,'\t'     ,'\t' },
	{ VK_ADD       ,0                ,'+'      ,'+'      ,'+'      ,'+' },
	{ VK_DIVIDE    ,0                ,'/'      ,'/'      ,'/'      ,'/' },
	{ VK_MULTIPLY  ,0                ,'*'      ,'*'      ,'*'      ,'*' },
	{ VK_SUBTRACT  ,0                ,'-'      ,'-'      ,'-'      ,'-' },
	{ 0            ,0                ,0        ,0        ,0        ,0 }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS5 aVkToWch5[] = {
	//                                |         |  Shift  |  Kana  | K-Shft |  Ctl+Alt|
	//                                |=========|=========|========|========|=========|
	{ '3'          ,         KANALOK ,'3'      ,0x00a7   ,WCH_A   ,WCH_AA  ,0x00b3 },
	{ '7'          ,         KANALOK ,'7'      ,'/'      ,WCH_YA  ,WCH_YAA ,'{' },
	{ '8'          ,         KANALOK ,'8'      ,'('      ,WCH_YU  ,WCH_YUU ,'[' },
	{ '9'          ,         KANALOK ,'9'      ,')'      ,WCH_YO  ,WCH_YOO ,']' },
	{ '0'          ,         KANALOK ,'0'      ,'='      ,WCH_WA  ,WCH_WO  ,'}' },
	// katakana syllable ho is separated from katakana prolonged sound mark
	{ VK_OEM_4     ,         KANALOK ,0x00df   ,'?'      ,WCH_HO  ,WCH_MD  ,'\\' },
	{ 'Q'          ,CAPLOK | KANALOK ,'q'      ,'Q'      ,WCH_TA  ,WCH_TA  ,'@' },
	{ 'E'          ,CAPLOK | KANALOK ,'e'      ,'E'      ,WCH_I   ,WCH_II  ,0x20ac },
	// additional yen character
	{ 'Y'          ,CAPLOK | KANALOK ,'y'      ,'Y'      ,WCH_TU  ,WCH_TUU ,0x00a5 },
	{ 'M'          ,CAPLOK | KANALOK ,'m'      ,'M'      ,WCH_MO  ,WCH_MO  ,0x00b5 },
	{ 0            ,0                ,0        ,0        ,0       ,0       ,0 }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS7 aVkToWch7[] = {
	//                       |         |  Shift  |  Kana  | K+Shft |  Ctl+Alt|  Ctrl   |  K+Ctrl   |
	//                       |=========|=========|========|========|=========|=========|===========|
	{ VK_OEM_1     ,KANALOK ,0x00fc   ,0x00dc   ,WCH_VS  ,WCH_OB  ,WCH_NONE ,0x001b   ,0x001b },
	{ VK_OEM_PLUS  ,KANALOK ,'+'      ,'*'      ,WCH_SVS ,WCH_CB  ,'~'      ,0x001d   ,0x001d },
	{ VK_OEM_2     ,KANALOK ,'#'      ,'\''     ,WCH_MU  ,WCH_MU  ,WCH_NONE ,0x001c   ,0x001c },
	// mimic JP behavior with (kana+)control 
	{ VK_OEM_102   ,0       ,'<'      ,'>'      ,WCH_MU  ,WCH_MU  ,'|'      ,0x001c   ,0x001c },
	{ VK_BACK      ,0       ,'\b'     ,'\b'     ,'\b'    ,'\b'    ,WCH_NONE ,0x007f   ,0x007f },
	{ VK_ESCAPE    ,0       ,0x001b   ,0x001b   ,0x001b  ,0x001b  ,WCH_NONE ,0x001b   ,0x001b },
	{ VK_RETURN    ,0       ,'\r'     ,'\r'     ,'\r'    ,'\r'    ,WCH_NONE ,'\n'     ,'\n' },
	{ VK_SPACE     ,0       ,' '      ,' '      ,' '     ,' '     ,WCH_NONE ,' '      ,' ' },
	{ VK_CANCEL    ,0       ,0x0003   ,0x0003   ,0x0003  ,0x0003  ,WCH_NONE ,0x0003   ,0x0003 },
	{ 0            ,0       ,0        ,0        ,0       ,0       ,0        ,0        ,0 }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS9 aVkToWch9[] = {
	//                       |         |  Shift  |  Kana  | K+Shft |  Ctl+Alt|  Ctrl   |  K+Ctrl   |S+Ctrl   |K-Shft+Ctrl|
	//                       |=========|=========|========|========|=========|=========|===========|=========|===========|
	{ '2'          ,KANALOK ,'2'      ,'\"'     ,WCH_HU  ,WCH_HU  ,0x00b2   ,WCH_NONE ,WCH_NONE ,0x0000     ,0x0000 },
	{ '6'          ,KANALOK ,'6'      ,'&'      ,WCH_O   ,WCH_OO  ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x001e     ,0x001e },
	// keep katakana prolonged sound mark on minus key
	{ VK_OEM_MINUS ,KANALOK ,'-'      ,'_'      ,WCH_ME  ,WCH_PS  ,WCH_NONE ,WCH_NONE ,WCH_NONE ,0x001f     ,0x001f },
	{ 0            ,0       ,0        ,0        ,0       ,0       ,0        ,0        ,0        ,0          ,0 }
};

// Put this last so that VkKeyScan interprets number characters
// as coming from the main section of the kbd (aVkToWch2 and
// aVkToWch5) before considering the numpad (aVkToWch1).

static ALLOC_SECTION_LDATA VK_TO_WCHARS4 aVkToWch1[] = {
	//                     |         |   SHIFT  |  KANA  | K+SHFT |
	//                     |         |==========|========|========|
	{ VK_NUMPAD0   , 0      ,  '0'   , WCH_NONE ,   '0'  ,WCH_NONE },
	{ VK_NUMPAD1   , 0      ,  '1'   , WCH_NONE ,   '1'  ,WCH_NONE },
	{ VK_NUMPAD2   , 0      ,  '2'   , WCH_NONE ,   '2'  ,WCH_NONE },
	{ VK_NUMPAD3   , 0      ,  '3'   , WCH_NONE ,   '3'  ,WCH_NONE },
	{ VK_NUMPAD4   , 0      ,  '4'   , WCH_NONE ,   '4'  ,WCH_NONE },
	{ VK_NUMPAD5   , 0      ,  '5'   , WCH_NONE ,   '5'  ,WCH_NONE },
	{ VK_NUMPAD6   , 0      ,  '6'   , WCH_NONE ,   '6'  ,WCH_NONE },
	{ VK_NUMPAD7   , 0      ,  '7'   , WCH_NONE ,   '7'  ,WCH_NONE },
	{ VK_NUMPAD8   , 0      ,  '8'   , WCH_NONE ,   '8'  ,WCH_NONE },
	{ VK_NUMPAD9   , 0      ,  '9'   , WCH_NONE ,   '9'  ,WCH_NONE },
	{ 0            , 0      ,  '\0'  , 0        ,   0    ,0 }
};

static ALLOC_SECTION_LDATA VK_TO_WCHAR_TABLE aVkToWcharTable[] = {
	{ (PVK_TO_WCHARS1)aVkToWch5, 5, sizeof(aVkToWch5[0]) },
	{ (PVK_TO_WCHARS1)aVkToWch7, 7, sizeof(aVkToWch7[0]) },
	{ (PVK_TO_WCHARS1)aVkToWch9, 9, sizeof(aVkToWch9[0]) },
	{ (PVK_TO_WCHARS1)aVkToWch4, 4, sizeof(aVkToWch4[0]) },
	{ (PVK_TO_WCHARS1)aVkToWch1, 4, sizeof(aVkToWch1[0]) },
	{ NULL, 0, 0 },
};

/***************************************************************************\
* aKeyNames[], aKeyNamesExt[]  - Virtual Scancode to Key Name tables
*
* Table attributes: Ordered Scan (by scancode), null-terminated
*
* Only the names of Extended, NumPad, Dead and Non-Printable keys are here.
* (Keys producing printable characters are named by that character)
\***************************************************************************/

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNames[] = {
	0x01,    L"ESC",
	0x0e,    L"R\x00DC" L"CK",
	0x0f,    L"TABULATOR",
	0x1c,    L"EINGABE",
	0x1d,    L"STRG",
	0x2a,    L"UMSCHALT",
	0x36,    L"UMSCHALT RECHTS",
	0x37,    L" (ZEHNERTASTATUR)",
	0x38,    L"ALT",
	0x39,    L"LEER",
	0x3a,    L"FESTSTELL",
	0x3b,    L"F1",
	0x3c,    L"F2",
	0x3d,    L"F3",
	0x3e,    L"F4",
	0x3f,    L"F5",
	0x40,    L"F6",
	0x41,    L"F7",
	0x42,    L"F8",
	0x43,    L"F9",
	0x44,    L"F10",
	0x45,    L"PAUSE",
	0x46,    L"ROLLEN-FESTSTELL",
	0x47,    L"7 (ZEHNERTASTATUR)",
	0x48,    L"8 (ZEHNERTASTATUR)",
	0x49,    L"9 (ZEHNERTASTATUR)",
	0x4a,    L"- (ZEHNERTASTATUR)",
	0x4b,    L"4 (ZEHNERTASTATUR)",
	0x4c,    L"5 (ZEHNERTASTATUR)",
	0x4d,    L"6 (ZEHNERTASTATUR)",
	0x4e,    L"+ (ZEHNERTASTATUR)",
	0x4f,    L"1 (ZEHNERTASTATUR)",
	0x50,    L"2 (ZEHNERTASTATUR)",
	0x51,    L"3 (ZEHNERTASTATUR)",
	0x52,    L"0 (ZEHNERTASTATUR)",
	0x53,    L"KOMMA (ZEHNERTASTATUR)",
	0x57,    L"F11",
	0x58,    L"F12",
	0   ,    NULL
};

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNamesExt[] = {
	0x1c,    L"EINGABE (ZEHNERTASTATUR)",
	0x1d,    L"STRG-RECHTS",
	0x35,    L" (ZEHNERTASTATUR)",
	0x37,    L"DRUCK",
	0x38,    L"ALT GR",
	0x45,    L"NUM-FESTSTELL",
	0x46,    L"UNTBR",
	0x47,    L"POS1",
	0x48,    L"NACH-OBEN",
	0x49,    L"BILD-NACH-OBEN",
	0x4b,    L"NACH-LINKS",
	0x4d,    L"NACH-RECHTS",
	0x4f,    L"ENDE",
	0x50,    L"NACH-UNTEN",
	0x51,    L"BILD-NACH-UNTEN",
	0x52,    L"EINFG",
	0x53,    L"ENTF",
	0x54,    L"<00>",
	0x56,    L"HILFE",
	0x5b,    L"LINKE WINDOWS",
	0x5c,    L"RECHTE WINDOWS",
	0x5d,    L"ANWENDUNG",
	0   ,    NULL
};

static ALLOC_SECTION_LDATA DEADKEY_LPWSTR aKeyNamesDead[] = {
	L"\x00b4"	L"AKUT",
	L"`"	L"GRAVIS",
	L"^"	L"ZIRKUMFLEX",
	NULL
};

static ALLOC_SECTION_LDATA DEADKEY aDeadKey[] = {
	DEADTRANS(L'a'   , L'^'   , 0x00e2 , 0x0000),
	DEADTRANS(L'e'   , L'^'   , 0x00ea , 0x0000),
	DEADTRANS(L'i'   , L'^'   , 0x00ee , 0x0000),
	DEADTRANS(L'o'   , L'^'   , 0x00f4 , 0x0000),
	DEADTRANS(L'u'   , L'^'   , 0x00fb , 0x0000),
	DEADTRANS(L'A'   , L'^'   , 0x00c2 , 0x0000),
	DEADTRANS(L'E'   , L'^'   , 0x00ca , 0x0000),
	DEADTRANS(L'I'   , L'^'   , 0x00ce , 0x0000),
	DEADTRANS(L'O'   , L'^'   , 0x00d4 , 0x0000),
	DEADTRANS(L'U'   , L'^'   , 0x00db , 0x0000),
	DEADTRANS(L' '   , L'^'   , L'^'   , 0x0000),

	DEADTRANS(L'a'   , 0x00b4 , 0x00e1 , 0x0000),
	DEADTRANS(L'e'   , 0x00b4 , 0x00e9 , 0x0000),
	DEADTRANS(L'i'   , 0x00b4 , 0x00ed , 0x0000),
	DEADTRANS(L'o'   , 0x00b4 , 0x00f3 , 0x0000),
	DEADTRANS(L'u'   , 0x00b4 , 0x00fa , 0x0000),
	DEADTRANS(L'y'   , 0x00b4 , 0x00fd , 0x0000),
	DEADTRANS(L'A'   , 0x00b4 , 0x00c1 , 0x0000),
	DEADTRANS(L'E'   , 0x00b4 , 0x00c9 , 0x0000),
	DEADTRANS(L'I'   , 0x00b4 , 0x00cd , 0x0000),
	DEADTRANS(L'O'   , 0x00b4 , 0x00d3 , 0x0000),
	DEADTRANS(L'U'   , 0x00b4 , 0x00da , 0x0000),
	DEADTRANS(L'Y'   , 0x00b4 , 0x00dd , 0x0000),
	DEADTRANS(L' '   , 0x00b4 , 0x00b4 , 0x0000),

	DEADTRANS(L'a'   , L'`'   , 0x00e0 , 0x0000),
	DEADTRANS(L'e'   , L'`'   , 0x00e8 , 0x0000),
	DEADTRANS(L'i'   , L'`'   , 0x00ec , 0x0000),
	DEADTRANS(L'o'   , L'`'   , 0x00f2 , 0x0000),
	DEADTRANS(L'u'   , L'`'   , 0x00f9 , 0x0000),
	DEADTRANS(L'A'   , L'`'   , 0x00c0 , 0x0000),
	DEADTRANS(L'E'   , L'`'   , 0x00c8 , 0x0000),
	DEADTRANS(L'I'   , L'`'   , 0x00cc , 0x0000),
	DEADTRANS(L'O'   , L'`'   , 0x00d2 , 0x0000),
	DEADTRANS(L'U'   , L'`'   , 0x00d9 , 0x0000),
	DEADTRANS(L' '   , L'`'   , L'`'   , 0x0000),

	0, 0
};

static ALLOC_SECTION_LDATA KBDTABLES KbdTables = {
	/*
	* Modifier keys
	*/
	&CharModifiers,

	/*
	* Characters tables
	*/
	aVkToWcharTable,

	/*
	* Diacritics
	*/
	aDeadKey,

	/*
	* Names of Keys
	*/
	aKeyNames,
	aKeyNamesExt,
	aKeyNamesDead,

	/*
	* Scan codes to Virtual Keys
	*/
	ausVK,
	sizeof(ausVK) / sizeof(ausVK[0]),
	aE0VscToVk,
	aE1VscToVk,

	/*
	* Locale-specific special processing
	*/
	MAKELONG(KLLF_ALTGR, KBD_VERSION),

	/*
	* Ligatures
	*/
	0,
	0,
	NULL,

	/*
	* Type and subtype.
	*/
	KEYBOARD_TYPE_GENERIC_101,  // Generic 101
	MAKEWORD(MICROSOFT_KBD_101_TYPE, NLSKBD_OEM_MICROSOFT),
};

PKBDTABLES KbdLayerDescriptor(VOID)
{
	return &KbdTables;
}

/***********************************************************************\
* VkToFuncTable_101[]
*
\***********************************************************************/

static ALLOC_SECTION_LDATA VK_F VkToFuncTable_101[] = {
	{
		VK_CAPITAL,                 // Base Vk
		KBDNLS_TYPE_TOGGLE,         // NLSFEProcType
		KBDNLS_INDEX_NORMAL,        // NLSFEProcCurrent
		0x08, /* 00001000 */        // NLSFEProcSwitch
		{                           // NLSFEProc
			{ KBDNLS_SEND_BASE_VK,0 },        // Base
			{ KBDNLS_ALPHANUM,0 },            // Shift
			{ KBDNLS_HIRAGANA,0 },            // Control
			{ KBDNLS_SEND_PARAM_VK,VK_KANA }, // Shift+Control
			{ KBDNLS_KATAKANA,0 },            // Alt
			{ KBDNLS_SEND_BASE_VK,0 },        // Shift+Alt
			{ KBDNLS_SEND_BASE_VK,0 },        // Control+Alt
			{ KBDNLS_SEND_BASE_VK,0 }         // Shift+Control+Alt
		},
		{                           // NLSFEProcAlt
			{ KBDNLS_SEND_PARAM_VK,VK_KANA }, // Base
			{ KBDNLS_SEND_PARAM_VK,VK_KANA }, // Shift
			{ KBDNLS_SEND_PARAM_VK,VK_KANA }, // Control
			{ KBDNLS_SEND_PARAM_VK,VK_KANA }, // Shift+Control
			{ KBDNLS_SEND_BASE_VK,0 },        // Alt
			{ KBDNLS_SEND_BASE_VK,0 },        // Shift+Alt
			{ KBDNLS_SEND_BASE_VK,0 },        // Control+Alt
			{ KBDNLS_SEND_BASE_VK,0 }         // Shift+Control+Alt
		}
	},
	{
		VK_OEM_3,            // Base Vk
		KBDNLS_TYPE_NORMAL,  // NLSFEProcType
		KBDNLS_INDEX_NORMAL, // NLSFEProcCurrent
		0,                   // NLSFEProcSwitch
		{                    // NLSFEProc
			{ KBDNLS_SEND_BASE_VK,0 },         // Base
			{ KBDNLS_SEND_BASE_VK,0 },         // Shift
			{ KBDNLS_SBCSDBCS,0 },             // Control
			{ KBDNLS_SEND_BASE_VK,0 },         // Shift+Control
			{ KBDNLS_SEND_PARAM_VK,VK_KANJI }, // Alt
			{ KBDNLS_SEND_BASE_VK,0 },         // Shift+Alt
			{ KBDNLS_SEND_BASE_VK,0 },         // Control+Alt
			{ KBDNLS_SEND_BASE_VK,0 }          // Shift+Control+Alt
		},
		{                    // NLSFEProcIndexAlt
			{ KBDNLS_NULL,0 },                 // Base
			{ KBDNLS_NULL,0 },                 // Shift
			{ KBDNLS_NULL,0 },                 // Control
			{ KBDNLS_NULL,0 },                 // Shift+Control
			{ KBDNLS_NULL,0 },                 // Alt
			{ KBDNLS_NULL,0 },                 // Shift+Alt
			{ KBDNLS_NULL,0 },                 // Control+Alt
			{ KBDNLS_NULL,0 }                  // Shift+Control+Alt
		}
	}
};

/***********************************************************************\
* KbdNlsTables
*
\***********************************************************************/

ALLOC_SECTION_LDATA KBDNLSTABLES KbdNlsTables101 = {
	0,                      // OEM ID (0 = Microsoft)
	0,                      // Information
	2,                      // Number of VK_F entry
	VkToFuncTable_101,      // Pointer to VK_F array
	0,                      // Number of MouseVk entry
	NULL                    // Pointer to MouseVk array
};

PKBDNLSTABLES KbdNlsLayerDescriptor(VOID)
{
	return &KbdNlsTables101;
}