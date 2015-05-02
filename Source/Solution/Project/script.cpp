#include "script.h"
#include "keyboard.h"
#include <string>
#include <ctime>
#pragma warning(disable : 4244 4305) // double <-> float conversions

namespace SUB{enum{
		// Define submenu (enum) indices here
/*base*/	CLOSED,
			MAINMENU,
			SETTINGS,
			SETTINGS_COLOURS,
			SETTINGS_COLOURS2,
			SETTINGS_FONTS,
			SETTINGS_FONTS2,
/*others*/
			SAMPLE,
			YOURSUB,


};};
namespace{
// Declare/Initialise global variables here.
char str[50];
bool controllerinput_bool = 1, menujustopened = 1, null;
enum ControllerInputs
{
	INPUT_NEXT_CAMERA = 0,
	INPUT_LOOK_LR = 1,
	INPUT_LOOK_UD = 2,
	INPUT_LOOK_UP_ONLY = 3,
	INPUT_LOOK_DOWN_ONLY = 4,
	INPUT_LOOK_LEFT_ONLY = 5,
	INPUT_LOOK_RIGHT_ONLY = 6,
	INPUT_CINEMATIC_SLOWMO = 7,
	INPUT_SCRIPTED_FLY_UD = 8,
	INPUT_SCRIPTED_FLY_LR = 9,
	INPUT_SCRIPTED_FLY_ZUP = 10,
	INPUT_SCRIPTED_FLY_ZDOWN = 11,
	INPUT_WEAPON_WHEEL_UD = 12,
	INPUT_WEAPON_WHEEL_LR = 13,
	INPUT_WEAPON_WHEEL_NEXT = 14,
	INPUT_WEAPON_WHEEL_PREV = 15,
	INPUT_SELECT_NEXT_WEAPON = 16,
	INPUT_SELECT_PREV_WEAPON = 17,
	INPUT_SKIP_CUTSCENE = 18,
	INPUT_CHARACTER_WHEEL = 19,
	INPUT_MULTIPLAYER_INFO = 20,
	INPUT_SPRINT = 21,
	INPUT_JUMP = 22,
	INPUT_ENTER = 23,
	INPUT_ATTACK = 24,
	INPUT_AIM = 25,
	INPUT_LOOK_BEHIND = 26,
	INPUT_PHONE = 27,
	INPUT_SPECIAL_ABILITY = 28,
	INPUT_SPECIAL_ABILITY_SECONDARY = 29,
	INPUT_MOVE_LR = 30,
	INPUT_MOVE_UD = 31,
	INPUT_MOVE_UP_ONLY = 32,
	INPUT_MOVE_DOWN_ONLY = 33,
	INPUT_MOVE_LEFT_ONLY = 34,
	INPUT_MOVE_RIGHT_ONLY = 35,
	INPUT_DUCK = 36,
	INPUT_SELECT_WEAPON = 37,
	INPUT_PICKUP = 38,
	INPUT_SNIPER_ZOOM = 39,
	INPUT_SNIPER_ZOOM_IN_ONLY = 40,
	INPUT_SNIPER_ZOOM_OUT_ONLY = 41,
	INPUT_SNIPER_ZOOM_IN_SECONDARY = 42,
	INPUT_SNIPER_ZOOM_OUT_SECONDARY = 43,
	INPUT_COVER = 44,
	INPUT_RELOAD = 45,
	INPUT_TALK = 46,
	INPUT_DETONATE = 47,
	INPUT_HUD_SPECIAL = 48,
	INPUT_ARREST = 49,
	INPUT_ACCURATE_AIM = 50,
	INPUT_CONTEXT = 51,
	INPUT_CONTEXT_SECONDARY = 52,
	INPUT_WEAPON_SPECIAL = 53,
	INPUT_WEAPON_SPECIAL_TWO = 54,
	INPUT_DIVE = 55,
	INPUT_DROP_WEAPON = 56,
	INPUT_DROP_AMMO = 57,
	INPUT_THROW_GRENADE = 58,
	INPUT_VEH_MOVE_LR = 59,
	INPUT_VEH_MOVE_UD = 60,
	INPUT_VEH_MOVE_UP_ONLY = 61,
	INPUT_VEH_MOVE_DOWN_ONLY = 62,
	INPUT_VEH_MOVE_LEFT_ONLY = 63,
	INPUT_VEH_MOVE_RIGHT_ONLY = 64,
	INPUT_VEH_SPECIAL = 65,
	INPUT_VEH_GUN_LR = 66,
	INPUT_VEH_GUN_UD = 67,
	INPUT_VEH_AIM = 68,
	INPUT_VEH_ATTACK = 69,
	INPUT_VEH_ATTACK2 = 70,
	INPUT_VEH_ACCELERATE = 71,
	INPUT_VEH_BRAKE = 72,
	INPUT_VEH_DUCK = 73,
	INPUT_VEH_HEADLIGHT = 74,
	INPUT_VEH_EXIT = 75,
	INPUT_VEH_HANDBRAKE = 76,
	INPUT_VEH_HOTWIRE_LEFT = 77,
	INPUT_VEH_HOTWIRE_RIGHT = 78,
	INPUT_VEH_LOOK_BEHIND = 79,
	INPUT_VEH_CIN_CAM = 80,
	INPUT_VEH_NEXT_RADIO = 81,
	INPUT_VEH_PREV_RADIO = 82,
	INPUT_VEH_NEXT_RADIO_TRACK = 83,
	INPUT_VEH_PREV_RADIO_TRACK = 84,
	INPUT_VEH_RADIO_WHEEL = 85,
	INPUT_VEH_HORN = 86,
	INPUT_VEH_FLY_THROTTLE_UP = 87,
	INPUT_VEH_FLY_THROTTLE_DOWN = 88,
	INPUT_VEH_FLY_YAW_LEFT = 89,
	INPUT_VEH_FLY_YAW_RIGHT = 90,
	INPUT_VEH_PASSENGER_AIM = 91,
	INPUT_VEH_PASSENGER_ATTACK = 92,
	INPUT_VEH_SPECIAL_ABILITY_FRANKLIN = 93,
	INPUT_VEH_STUNT_UD = 94,
	INPUT_VEH_CINEMATIC_UD = 95,
	INPUT_VEH_CINEMATIC_UP_ONLY = 96,
	INPUT_VEH_CINEMATIC_DOWN_ONLY = 97,
	INPUT_VEH_CINEMATIC_LR = 98,
	INPUT_VEH_SELECT_NEXT_WEAPON = 99,
	INPUT_VEH_SELECT_PREV_WEAPON = 100,
	INPUT_VEH_ROOF = 101,
	INPUT_VEH_JUMP = 102,
	INPUT_VEH_GRAPPLING_HOOK = 103,
	INPUT_VEH_SHUFFLE = 104,
	INPUT_VEH_DROP_PROJECTILE = 105,
	INPUT_VEH_MOUSE_CONTROL_OVERRIDE = 106,
	INPUT_VEH_FLY_ROLL_LR = 107,
	INPUT_VEH_FLY_ROLL_LEFT_ONLY = 108,
	INPUT_VEH_FLY_ROLL_RIGHT_ONLY = 109,
	INPUT_VEH_FLY_PITCH_UD = 110,
	INPUT_VEH_FLY_PITCH_UP_ONLY = 111,
	INPUT_VEH_FLY_PITCH_DOWN_ONLY = 112,
	INPUT_VEH_FLY_UNDERCARRIAGE = 113,
	INPUT_VEH_FLY_ATTACK = 114,
	INPUT_VEH_FLY_SELECT_NEXT_WEAPON = 115,
	INPUT_VEH_FLY_SELECT_PREV_WEAPON = 116,
	INPUT_VEH_FLY_SELECT_TARGET_LEFT = 117,
	INPUT_VEH_FLY_SELECT_TARGET_RIGHT = 118,
	INPUT_VEH_FLY_VERTICAL_FLIGHT_MODE = 119,
	INPUT_VEH_FLY_DUCK = 120,
	INPUT_VEH_FLY_ATTACK_CAMERA = 121,
	INPUT_VEH_FLY_MOUSE_CONTROL_OVERRIDE = 122,
	INPUT_VEH_SUB_TURN_LR = 123,
	INPUT_VEH_SUB_TURN_LEFT_ONLY = 124,
	INPUT_VEH_SUB_TURN_RIGHT_ONLY = 125,
	INPUT_VEH_SUB_PITCH_UD = 126,
	INPUT_VEH_SUB_PITCH_UP_ONLY = 127,
	INPUT_VEH_SUB_PITCH_DOWN_ONLY = 128,
	INPUT_VEH_SUB_THROTTLE_UP = 129,
	INPUT_VEH_SUB_THROTTLE_DOWN = 130,
	INPUT_VEH_SUB_ASCEND = 131,
	INPUT_VEH_SUB_DESCEND = 132,
	INPUT_VEH_SUB_TURN_HARD_LEFT = 133,
	INPUT_VEH_SUB_TURN_HARD_RIGHT = 134,
	INPUT_VEH_SUB_MOUSE_CONTROL_OVERRIDE = 135,
	INPUT_VEH_PUSHBIKE_PEDAL = 136,
	INPUT_VEH_PUSHBIKE_SPRINT = 137,
	INPUT_VEH_PUSHBIKE_FRONT_BRAKE = 138,
	INPUT_VEH_PUSHBIKE_REAR_BRAKE = 139,
	INPUT_MELEE_ATTACK_LIGHT = 140,
	INPUT_MELEE_ATTACK_HEAVY = 141,
	INPUT_MELEE_ATTACK_ALTERNATE = 142,
	INPUT_MELEE_BLOCK = 143,
	INPUT_PARACHUTE_DEPLOY = 144,
	INPUT_PARACHUTE_DETACH = 145,
	INPUT_PARACHUTE_TURN_LR = 146,
	INPUT_PARACHUTE_TURN_LEFT_ONLY = 147,
	INPUT_PARACHUTE_TURN_RIGHT_ONLY = 148,
	INPUT_PARACHUTE_PITCH_UD = 149,
	INPUT_PARACHUTE_PITCH_UP_ONLY = 150,
	INPUT_PARACHUTE_PITCH_DOWN_ONLY = 151,
	INPUT_PARACHUTE_BRAKE_LEFT = 152,
	INPUT_PARACHUTE_BRAKE_RIGHT = 153,
	INPUT_PARACHUTE_SMOKE = 154,
	INPUT_PARACHUTE_PRECISION_LANDING = 155,
	INPUT_MAP = 156,
	INPUT_SELECT_WEAPON_UNARMED = 157,
	INPUT_SELECT_WEAPON_MELEE = 158,
	INPUT_SELECT_WEAPON_HANDGUN = 159,
	INPUT_SELECT_WEAPON_SHOTGUN = 160,
	INPUT_SELECT_WEAPON_SMG = 161,
	INPUT_SELECT_WEAPON_AUTO_RIFLE = 162,
	INPUT_SELECT_WEAPON_SNIPER = 163,
	INPUT_SELECT_WEAPON_HEAVY = 164,
	INPUT_SELECT_WEAPON_SPECIAL = 165,
	INPUT_SELECT_CHARACTER_MICHAEL = 166,
	INPUT_SELECT_CHARACTER_FRANKLIN = 167,
	INPUT_SELECT_CHARACTER_TREVOR = 168,
	INPUT_SELECT_CHARACTER_MULTIPLAYER = 169,
	INPUT_SAVE_REPLAY_CLIP = 170,
	INPUT_SPECIAL_ABILITY_PC = 171,
	INPUT_CELLPHONE_UP = 172,
	INPUT_CELLPHONE_DOWN = 173,
	INPUT_CELLPHONE_LEFT = 174,
	INPUT_CELLPHONE_RIGHT = 175,
	INPUT_CELLPHONE_SELECT = 176,
	INPUT_CELLPHONE_CANCEL = 177,
	INPUT_CELLPHONE_OPTION = 178,
	INPUT_CELLPHONE_EXTRA_OPTION = 179,
	INPUT_CELLPHONE_SCROLL_FORWARD = 180,
	INPUT_CELLPHONE_SCROLL_BACKWARD = 181,
	INPUT_CELLPHONE_CAMERA_FOCUS_LOCK = 182,
	INPUT_CELLPHONE_CAMERA_GRID = 183,
	INPUT_CELLPHONE_CAMERA_SELFIE = 184,
	INPUT_CELLPHONE_CAMERA_DOF = 185,
	INPUT_CELLPHONE_CAMERA_EXPRESSION = 186,
	INPUT_FRONTEND_DOWN = 187,
	INPUT_FRONTEND_UP = 188,
	INPUT_FRONTEND_LEFT = 189,
	INPUT_FRONTEND_RIGHT = 190,
	INPUT_FRONTEND_RDOWN = 191,
	INPUT_FRONTEND_RUP = 192,
	INPUT_FRONTEND_RLEFT = 193,
	INPUT_FRONTEND_RRIGHT = 194,
	INPUT_FRONTEND_AXIS_X = 195,
	INPUT_FRONTEND_AXIS_Y = 196,
	INPUT_FRONTEND_RIGHT_AXIS_X = 197,
	INPUT_FRONTEND_RIGHT_AXIS_Y = 198,
	INPUT_FRONTEND_PAUSE = 199,
	INPUT_FRONTEND_PAUSE_ALTERNATE = 200,
	INPUT_FRONTEND_ACCEPT = 201,
	INPUT_FRONTEND_CANCEL = 202,
	INPUT_FRONTEND_X = 203,
	INPUT_FRONTEND_Y = 204,
	INPUT_FRONTEND_LB = 205,
	INPUT_FRONTEND_RB = 206,
	INPUT_FRONTEND_LT = 207,
	INPUT_FRONTEND_RT = 208,
	INPUT_FRONTEND_LS = 209,
	INPUT_FRONTEND_RS = 210,
	INPUT_FRONTEND_LEADERBOARD = 211,
	INPUT_FRONTEND_SOCIAL_CLUB = 212,
	INPUT_FRONTEND_SOCIAL_CLUB_SECONDARY = 213,
	INPUT_FRONTEND_DELETE = 214,
	INPUT_FRONTEND_ENDSCREEN_ACCEPT = 215,
	INPUT_FRONTEND_ENDSCREEN_EXPAND = 216,
	INPUT_FRONTEND_SELECT = 217,
	INPUT_SCRIPT_LEFT_AXIS_X = 218,
	INPUT_SCRIPT_LEFT_AXIS_Y = 219,
	INPUT_SCRIPT_RIGHT_AXIS_X = 220,
	INPUT_SCRIPT_RIGHT_AXIS_Y = 221,
	INPUT_SCRIPT_RUP = 222,
	INPUT_SCRIPT_RDOWN = 223,
	INPUT_SCRIPT_RLEFT = 224,
	INPUT_SCRIPT_RRIGHT = 225,
	INPUT_SCRIPT_LB = 226,
	INPUT_SCRIPT_RB = 227,
	INPUT_SCRIPT_LT = 228,
	INPUT_SCRIPT_RT = 229,
	INPUT_SCRIPT_LS = 230,
	INPUT_SCRIPT_RS = 231,
	INPUT_SCRIPT_PAD_UP = 232,
	INPUT_SCRIPT_PAD_DOWN = 233,
	INPUT_SCRIPT_PAD_LEFT = 234,
	INPUT_SCRIPT_PAD_RIGHT = 235,
	INPUT_SCRIPT_SELECT = 236,
	INPUT_CURSOR_ACCEPT = 237,
	INPUT_CURSOR_CANCEL = 238,
	INPUT_CURSOR_X = 239,
	INPUT_CURSOR_Y = 240,
	INPUT_CURSOR_SCROLL_UP = 241,
	INPUT_CURSOR_SCROLL_DOWN = 242,
	INPUT_ENTER_CHEAT_CODE = 243,
	INPUT_INTERACTION_MENU = 244,
	INPUT_MP_TEXT_CHAT_ALL = 245,
	INPUT_MP_TEXT_CHAT_TEAM = 246,
	INPUT_MP_TEXT_CHAT_FRIENDS = 247,
	INPUT_MP_TEXT_CHAT_CREW = 248,
	INPUT_PUSH_TO_TALK = 249,
	INPUT_CREATOR_LS = 250,
	INPUT_CREATOR_RS = 251,
	INPUT_CREATOR_LT = 252,
	INPUT_CREATOR_RT = 253,
	INPUT_CREATOR_MENU_TOGGLE = 254,
	INPUT_CREATOR_ACCEPT = 255,
	INPUT_CREATOR_DELETE = 256,
	INPUT_ATTACK2 = 257,
	INPUT_RAPPEL_JUMP = 258,
	INPUT_RAPPEL_LONG_JUMP = 259,
	INPUT_RAPPEL_SMASH_WINDOW = 260,
	INPUT_PREV_WEAPON = 261,
	INPUT_NEXT_WEAPON = 262,
	INPUT_MELEE_ATTACK1 = 263,
	INPUT_MELEE_ATTACK2 = 264,
	INPUT_WHISTLE = 265,
	INPUT_MOVE_LEFT = 266,
	INPUT_MOVE_RIGHT = 267,
	INPUT_MOVE_UP = 268,
	INPUT_MOVE_DOWN = 269,
	INPUT_LOOK_LEFT = 270,
	INPUT_LOOK_RIGHT = 271,
	INPUT_LOOK_UP = 272,
	INPUT_LOOK_DOWN = 273,
	INPUT_SNIPER_ZOOM_IN = 274,
	INPUT_SNIPER_ZOOM_OUT = 275,
	INPUT_SNIPER_ZOOM_IN_ALTERNATE = 276,
	INPUT_SNIPER_ZOOM_OUT_ALTERNATE = 277,
	INPUT_VEH_MOVE_LEFT = 278,
	INPUT_VEH_MOVE_RIGHT = 279,
	INPUT_VEH_MOVE_UP = 280,
	INPUT_VEH_MOVE_DOWN = 281,
	INPUT_VEH_GUN_LEFT = 282,
	INPUT_VEH_GUN_RIGHT = 283,
	INPUT_VEH_GUN_UP = 284,
	INPUT_VEH_GUN_DOWN = 285,
	INPUT_VEH_LOOK_LEFT = 286,
	INPUT_VEH_LOOK_RIGHT = 287,
	INPUT_REPLAY_START_STOP_RECORDING = 288,
	INPUT_REPLAY_START_STOP_RECORDING_SECONDARY = 289,
	INPUT_SCALED_LOOK_LR = 290,
	INPUT_SCALED_LOOK_UD = 291,
	INPUT_SCALED_LOOK_UP_ONLY = 292,
	INPUT_SCALED_LOOK_DOWN_ONLY = 293,
	INPUT_SCALED_LOOK_LEFT_ONLY = 294,
	INPUT_SCALED_LOOK_RIGHT_ONLY = 295,
	INPUT_REPLAY_MARKER_DELETE = 296,
	INPUT_REPLAY_CLIP_DELETE = 297,
	INPUT_REPLAY_PAUSE = 298,
	INPUT_REPLAY_REWIND = 299,
	INPUT_REPLAY_FFWD = 300,
	INPUT_REPLAY_NEWMARKER = 301,
	INPUT_REPLAY_RECORD = 302,
	INPUT_REPLAY_SCREENSHOT = 303,
	INPUT_REPLAY_HIDEHUD = 304,
	INPUT_REPLAY_STARTPOINT = 305,
	INPUT_REPLAY_ENDPOINT = 306,
	INPUT_REPLAY_ADVANCE = 307,
	INPUT_REPLAY_BACK = 308,
	INPUT_REPLAY_TOOLS = 309,
	INPUT_REPLAY_RESTART = 310,
	INPUT_REPLAY_SHOWHOTKEY = 311,
	INPUT_REPLAY_CYCLEMARKERLEFT = 312,
	INPUT_REPLAY_CYCLEMARKERRIGHT = 313,
	INPUT_REPLAY_FOVINCREASE = 314,
	INPUT_REPLAY_FOVDECREASE = 315,
	INPUT_REPLAY_CAMERAUP = 316,
	INPUT_REPLAY_CAMERADOWN = 317,
	INPUT_REPLAY_SAVE = 318,
	INPUT_REPLAY_TOGGLETIME = 319,
	INPUT_REPLAY_TOGGLETIPS = 320,
	INPUT_REPLAY_PREVIEW = 321,
	INPUT_REPLAY_TOGGLE_TIMELINE = 322,
	INPUT_REPLAY_TIMELINE_PICKUP_CLIP = 323,
	INPUT_REPLAY_TIMELINE_DUPLICATE_CLIP = 324,
	INPUT_REPLAY_TIMELINE_PLACE_CLIP = 325,
	INPUT_REPLAY_CTRL = 326,
	INPUT_REPLAY_TIMELINE_SAVE = 327,
	INPUT_REPLAY_PREVIEW_AUDIO = 328,
	INPUT_VEH_DRIVE_LOOK = 329,
	INPUT_VEH_DRIVE_LOOK2 = 330,
	INPUT_VEH_FLY_ATTACK2 = 331,
	INPUT_RADIO_WHEEL_UD = 332,
	INPUT_RADIO_WHEEL_LR = 333,
	INPUT_VEH_SLOWMO_UD = 334,
	INPUT_VEH_SLOWMO_UP_ONLY = 335,
	INPUT_VEH_SLOWMO_DOWN_ONLY = 336,
	INPUT_MAP_POI = 337
};
namespace COL{ enum COL { TITLEBOX, BACKGROUND, TITLETEXT, OPTIONTEXT, OPTIONCOUNT, SELECTEDTEXT, BREAKS, SELECTIONHIGH }; }
namespace FON{ enum FON { TITLE = 10, OPTION, SELECTEDTEXT, BREAKS }; }
int *settings_font;
RGBA *settings_rgba;
RGBA titlebox = { 167, 23, 172, 255 };
RGBA BG = { 20, 20, 20, 200 };
RGBA titletext = { 255, 255, 255, 255 };
RGBA optiontext = { 255, 255, 255, 255 };
RGBA optioncount = { 255, 255, 255, 255 };
RGBA selectedtext = { 255, 255, 255, 255 };
RGBA optionbreaks = { 255, 255, 255, 240 };
RGBA selectionhi = { 255, 255, 255, 110 };
int font_title = 7, font_options = 4, font_selection = 4, font_breaks = 1;
float menuPos = 0, OptionY;
int screen_res_x, screen_res_y;
DWORD myVeh, cam_gta2;
float current_timescale = 1.0f;



// Booleans for loops go here:
bool loop_massacre_mode = 0, loop_RainbowBoxes = 0, loop_gravity_gun = 0, loop_gta2cam = 0;
}
namespace{
	// Declare subroutines here.



}
namespace{
	// Define subroutines here.

void VectorToFloat(Vector3 unk, float *Out)
{
	Out[0] = unk.x;
	Out[1] = unk.y;
	Out[2] = unk.z;
}
int RandomRGB()
{
	srand(GetTickCount());
	return (GET_RANDOM_INT_IN_RANGE(0, 255));
}
bool get_key_pressed(int nVirtKey)
{
	return (GetAsyncKeyState(nVirtKey) & 0x8000) != 0;
}
bool Check_self_in_vehicle()
{
	if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0)) return true; else return false;
}
int FindFreeCarSeat(DWORD vehicle)
{
	int max = GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(vehicle) - 2;
	for (static int tick = -1; tick <= max; tick++)
	{
		if (IS_VEHICLE_SEAT_FREE(vehicle, tick))
		{
			return tick;
		}
	}

	return -1;
}
void offset_from_entity(int entity, float X, float Y, float Z, float * Out)
{
	VectorToFloat(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity, X, Y, Z), Out);
}
void RequestControlOfEnt(DWORD entity)
{
	int tick = 0;

	while (!NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 12)
	{
		NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
}
void RequestControlOfid(DWORD netid)
{
	int tick = 0;

	while (!NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 12)
	{
		NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}
void RequestModel(DWORD Hash)
{
	REQUEST_MODEL(Hash);
	while (!(HAS_MODEL_LOADED(Hash)))
	{
		WAIT(5);
	}
}
int PlaceObject(DWORD Hash, float X, float Y, float Z, float Pitch, float Roll, float Yaw)
{
	RequestModel(Hash);
	static DWORD object = CREATE_OBJECT(Hash, X, Y, Z, 1, 1, 0);
	SET_ENTITY_ROTATION(object, Pitch, Roll, Yaw, 2, 1);
	FREEZE_ENTITY_POSITION(object, 1);
	SET_ENTITY_LOD_DIST(object, 696969);
	SET_MODEL_AS_NO_LONGER_NEEDED(Hash);
	SET_OBJECT_AS_NO_LONGER_NEEDED(&object);

	return object;
}
void setupdraw()
{
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(0.4f, 0.4f);
	SET_TEXT_COLOUR(255, 255, 255, 255);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(0);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_EDGE(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
}
void drawstring(char* text, float X, float Y)
{
	_SET_TEXT_ENTRY("STRING");
	_ADD_TEXT_COMPONENT_STRING(text);
	_DRAW_TEXT(X, Y);
}
void drawinteger(int text, float X, float Y)
{
	_SET_TEXT_ENTRY("NUMBER");
	ADD_TEXT_COMPONENT_INTEGER(text);
	_DRAW_TEXT(X, Y);
}
void drawfloat(float text, DWORD decimal_places, float X, float Y)
{
	_SET_TEXT_ENTRY("NUMBER");
	ADD_TEXT_COMPONENT_FLOAT(text, decimal_places);
	_DRAW_TEXT(X, Y);
}
void PlaySoundFrontend(char* sound_dict, char* sound_name)
{
	PLAY_SOUND_FRONTEND(-1, sound_name, sound_dict, 0);
}
void PlaySoundFrontend_default(char* sound_name)
{
	PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}
bool Check_compare_string_length(char* unk1, size_t max_length)
{
	if (strlen(unk1) <= max_length) return true; else return false;
}
char* AddStrings(char* string1, char* string2)
{
	memset(str, 0, sizeof(str));
	strcpy_s(str, "");
	strcpy_s(str, string1);
	strcat_s(str, string2);
	return str;
}
char* AddInt_S(char* string1, int int2)
{
	static char* Return;
	printf(Return, "%i", int2);
	Return = AddStrings(string1, Return);
	return Return;

	/*std::string string2 = string1;
	string2 += std::to_string(int2);

	char * Char = new char[string2.size() + 1];
	std::copy(string2.begin(), string2.end(), Char);
	Char[string2.size()] = '\0';

	static char* Return = Char;
	delete[] Char;
	return Return;*/
}
char* keyboard()
{
	float i = 2.0000f;
	while (i > 0.4750f)
	{
		WAIT(10);
		DRAW_RECT(i, 0.9389f, 0.3875f, 0.736f, titlebox.R, titlebox.G, titlebox.B, 120);
		i -= 0.0050f;
	}

	static char* tempChar;
	bool j;
	if (Check_self_in_vehicle()) j = true; else j = false;

	while (!IsKeyDown(VK_RETURN))
	{
		WAIT(5);
		DRAW_RECT(i, 0.9389f, 0.3875f, 0.736f, titlebox.R, titlebox.G, titlebox.B, 120);
		setupdraw();
		SET_TEXT_FONT(1);
		drawstring("INPUT:", 0.2836f, 0.9129f);


		if (IsKeyJustUp('1')) AddStrings(tempChar, "1");
		else if (IsKeyJustUp('2')) AddStrings(tempChar, "2");
		else if (IsKeyJustUp('3')) AddStrings(tempChar, "3");
		else if (IsKeyJustUp('4')) AddStrings(tempChar, "4");
		else if (IsKeyJustUp('5')) AddStrings(tempChar, "5");
		else if (IsKeyJustUp('6')) AddStrings(tempChar, "6");
		else if (IsKeyJustUp('7')) AddStrings(tempChar, "7");
		else if (IsKeyJustUp('8')) AddStrings(tempChar, "8");
		else if (IsKeyJustUp('9')) AddStrings(tempChar, "9");
		else if (IsKeyJustUp('0')) AddStrings(tempChar, "0");
		else if (IsKeyJustUp('A')) AddStrings(tempChar, "A");
		else if (IsKeyJustUp('B')) AddStrings(tempChar, "B");
		else if (IsKeyJustUp('C')) AddStrings(tempChar, "C");
		else if (IsKeyJustUp('D')) AddStrings(tempChar, "D");
		else if (IsKeyJustUp('E')) AddStrings(tempChar, "E");
		else if (IsKeyJustUp('F')){ AddStrings(tempChar, "F"); if (j) SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), myVeh, FindFreeCarSeat(myVeh)); }
		else if (IsKeyJustUp('G')) AddStrings(tempChar, "G");
		else if (IsKeyJustUp('H')) AddStrings(tempChar, "H");
		else if (IsKeyJustUp('I')) AddStrings(tempChar, "I");
		else if (IsKeyJustUp('J')) AddStrings(tempChar, "J");
		else if (IsKeyJustUp('K')) AddStrings(tempChar, "K");
		else if (IsKeyJustUp('L')) AddStrings(tempChar, "L");
		else if (IsKeyJustUp('M')) AddStrings(tempChar, "M");
		else if (IsKeyJustUp('N')) AddStrings(tempChar, "N");
		else if (IsKeyJustUp('O')) AddStrings(tempChar, "O");
		else if (IsKeyJustUp('P')) AddStrings(tempChar, "P");
		else if (IsKeyJustUp('Q')) AddStrings(tempChar, "Q");
		else if (IsKeyJustUp('R')) AddStrings(tempChar, "R");
		else if (IsKeyJustUp('S')) AddStrings(tempChar, "S");
		else if (IsKeyJustUp('T')) AddStrings(tempChar, "T");
		else if (IsKeyJustUp('U')) AddStrings(tempChar, "U");
		else if (IsKeyJustUp('V')) AddStrings(tempChar, "V");
		else if (IsKeyJustUp('W')) AddStrings(tempChar, "W");
		else if (IsKeyJustUp('X')) AddStrings(tempChar, "X");
		else if (IsKeyJustUp('Y')) AddStrings(tempChar, "Y");
		else if (IsKeyJustUp('Z')) AddStrings(tempChar, "Z");
		else if (IsKeyJustUp(VK_ESCAPE)) return "";
		else if (IsKeyJustUp(VK_SPACE)) AddStrings(tempChar, " ");
		else if (IsKeyJustUp(VK_BACK) && strlen(tempChar) > 0){ std::string str(tempChar); str.pop_back(); }

		setupdraw();
		SET_TEXT_FONT(14);
		SET_TEXT_CENTRE(1);
		drawstring(tempChar, 0.46, 0.9);

	}
	return tempChar;
}
int StringToInt(char* text)
{
	static DWORD tempp;
	if (text == "") return NULL;
	if (STRING_TO_INT((DWORD*)text, &tempp)) return NULL;

	return tempp;
}
void PrintStringBottomCentre(char* text)
{
	_0xB87A37EEB7FAA67D("STRING");
	_ADD_TEXT_COMPONENT_STRING(text);
	_0x9D77056A530643F6(2000, 1);
}
void PrintFloatBottomCentre(float text, __int8 decimal_places)
{
	_0xB87A37EEB7FAA67D("NUMBER");
	ADD_TEXT_COMPONENT_FLOAT(text, (DWORD)decimal_places);
	_0x9D77056A530643F6(2000, 1);
}
void PrintBottomLeft(char* text)
{
	_0x202709F4C58A0424("STRING");
	_ADD_TEXT_COMPONENT_STRING(text);
	_0x44FA03975424A0EE(0, 1); // Not sure if right native
}
void PrintError_InvalidInput()
{
	PrintStringBottomCentre("~r~Error:~s~ Invalid Input.");
}
class menu
{
public:
	static unsigned __int16 currentsub;
	static unsigned __int16 currentop;
	static unsigned __int16 currentop_w_breaks;
	static unsigned __int16 totalop;
	static unsigned __int16 printingop;
	static unsigned __int16 breakcount;
	static unsigned __int16 totalbreaks;
	static unsigned __int8 breakscroll;
	static __int16 currentsub_ar_index;
	static int currentsub_ar[20];
	static int currentop_ar[20];
	static int SetSub_delayed;
	static unsigned long int livetimer;

	static void loops();
	static void sub_handler();
	static void submenu_switch();
	static void DisableControls()
	{
		HIDE_HELP_TEXT_THIS_FRAME();
		SET_CINEMATIC_BUTTON_ACTIVE(1);
		DISABLE_CONTROL_ACTION(0, INPUT_NEXT_CAMERA, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_SELECT_NEXT_WEAPON, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_CIN_CAM, controllerinput_bool);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_X);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_ACCEPT);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_CANCEL);
		DISABLE_CONTROL_ACTION(0, INPUT_HUD_SPECIAL, controllerinput_bool);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_DOWN);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_UP);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_ACCEPT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_CANCEL, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_LEFT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_RIGHT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_DOWN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_UP, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_RDOWN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_ACCEPT, controllerinput_bool);
		HIDE_HUD_COMPONENT_THIS_FRAME(10);
		HIDE_HUD_COMPONENT_THIS_FRAME(6);
		HIDE_HUD_COMPONENT_THIS_FRAME(7);
		HIDE_HUD_COMPONENT_THIS_FRAME(9);
		HIDE_HUD_COMPONENT_THIS_FRAME(8);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_LEFT);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_RIGHT);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_UNARMED, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_MELEE, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_HANDGUN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_SHOTGUN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_SMG, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_AUTO_RIFLE, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_SNIPER, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_HEAVY, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_WEAPON_SPECIAL, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_WEAPON_WHEEL_NEXT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_WEAPON_WHEEL_PREV, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_WEAPON_SPECIAL_TWO, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_DIVE, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_MELEE_ATTACK_LIGHT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_MELEE_ATTACK_HEAVY, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_MELEE_BLOCK, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_ARREST, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_HEADLIGHT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_RADIO_WHEEL, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_CONTEXT, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_RELOAD, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_DIVE, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_CIN_CAM, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_JUMP, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_SELECT_NEXT_WEAPON, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_VEH_FLY_SELECT_NEXT_WEAPON, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_CHARACTER_FRANKLIN, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_CHARACTER_MICHAEL, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_CHARACTER_TREVOR, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_SELECT_CHARACTER_MULTIPLAYER, controllerinput_bool);
		DISABLE_CONTROL_ACTION(0, INPUT_CHARACTER_WHEEL, controllerinput_bool);
	}
	static void base()
	{
		GET_SCREEN_RESOLUTION(&screen_res_x, &screen_res_y); // Get screen res
		if (menu::currentsub != SUB::CLOSED)
		{
			DWORD dword = (DWORD)("CommonMenu");
			if (!HAS_STREAMED_TEXTURE_DICT_LOADED(&dword)){ REQUEST_STREAMED_TEXTURE_DICT(&dword, 0); }
			background();
			optionhi();
		}
	}
	static void background()
	{
		float temp;
		if (totalop > 14) temp = 14; else temp = (float)totalop; // Calculate last option number to draw rect

		// Calculate Y Coord
		float bg_Y = ((temp * 0.035f) / 2.0f) + 0.159f;
		float bg_length = temp * 0.035f;

		// Draw titlebox
		DRAW_RECT(0.16f + menuPos, 0.1175f, 0.20f, 0.083f, titlebox.R, titlebox.G, titlebox.B, titlebox.A);

		// Draw background
		DRAW_RECT(0.16f + menuPos, bg_Y, 0.20f, bg_length, BG.R, BG.G, BG.B, BG.A);

		// Draw scroller indicator rect
		if (totalop > 14) temp = 14.0f; else temp = (float)totalop;
		float scr_rect_Y = ((temp + 1.0f) * 0.035f) + 0.1415f;
		DRAW_RECT(0.16f + menuPos, scr_rect_Y, 0.20f, 0.0345f, BG.R, BG.G, BG.B, BG.A);

		// Draw thin line over scroller indicator rect
		if (totalop < 14) DRAW_RECT(0.16f + menuPos, (float)(totalop)* 0.035f + 0.16f, 0.20f, 0.0022f, 255, 255, 255, 255);
		else DRAW_RECT(0.16f + menuPos, 14.0f * 0.035f + 0.16f, 0.20f, 0.0022f, 255, 255, 255, 255);

		// Draw scroller indicator
		DWORD dword = (DWORD)("CommonMenu");
		if ((totalop > 14) && HAS_STREAMED_TEXTURE_DICT_LOADED(&dword))
		{
			DWORD dword2 = (DWORD)"shop_arrows_upANDdown";
			DWORD dword3 = (DWORD)"arrowright";
			Vector3 texture_res = GET_TEXTURE_RESOLUTION(&dword, &dword2);

			temp = ((14.0f + 1.0f) * 0.035f) + 0.1259f;

			if (currentop == 1)	DRAW_SPRITE(dword, dword3, 0.16f + menuPos, temp, texture_res.x / (float)screen_res_x, texture_res.y / (float)screen_res_y, 270.0f, titlebox.R, titlebox.G, titlebox.B, 255);
			else if (currentop == totalop) DRAW_SPRITE(dword, dword3, 0.16f + menuPos, temp, texture_res.x / (float)screen_res_x, texture_res.y / (float)screen_res_y, 90.0f, titlebox.R, titlebox.G, titlebox.B, 255);
			else DRAW_SPRITE(dword, dword2, 0.16f + menuPos, temp, texture_res.x / (float)screen_res_x, texture_res.y / (float)screen_res_y, 0.0f, titlebox.R, titlebox.G, titlebox.B, 255);

		}

		// Draw option count
		temp = scr_rect_Y - 0.0124f;
		setupdraw();
		SET_TEXT_FONT(0);
		SET_TEXT_SCALE(0.0f, 0.26f);
		SET_TEXT_COLOUR(optioncount.R, optioncount.G, optioncount.B, optioncount.A);

		_SET_TEXT_ENTRY("CM_ITEM_COUNT");
		ADD_TEXT_COMPONENT_INTEGER(currentop); // ! currentop_w_breaks
		ADD_TEXT_COMPONENT_INTEGER(totalop); // ! totalop - totalbreaks
		_DRAW_TEXT(0.2205f + menuPos, temp);
	}
	static void optionhi()
	{
		float Y_coord;
		if (currentop > 14) Y_coord = 14.0f; else Y_coord = (float)currentop;

		Y_coord = (Y_coord * 0.035f) + 0.1415f;
		DRAW_RECT(0.16f + menuPos, Y_coord, 0.20f, 0.035f, selectionhi.R, selectionhi.G, selectionhi.B, selectionhi.A);
	}
	static bool isBinds()
	{
		// Open menu - RB + LB / NUM4 + NUM6
		return ((IS_CONTROL_PRESSED(2, INPUT_FRONTEND_RB) && IS_CONTROL_PRESSED(2, INPUT_FRONTEND_LB)) || (IsKeyDown(VK_NUMPAD4) && IsKeyDown(VK_NUMPAD6)));
	}
	static void while_closed()
	{
		if (isBinds())
		{
			PlaySoundFrontend("FocusIn", "HintCamSounds");
			currentsub = 1;
			currentsub_ar_index = 0;
			currentop = 1;
		}
	}
	static void while_opened()
	{
		totalop = printingop; printingop = 0;
		totalbreaks = breakcount; breakcount = 0; breakscroll = 0;

		if (IS_PAUSE_MENU_ACTIVE()) SetSub_closed();

		DISPLAY_AMMO_THIS_FRAME(0);
		DISPLAY_CASH(0);
		SET_RADAR_ZOOM(0);

		DisableControls();

		// Scroll up
		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_PAD_UP) || IsKeyJustUp(VK_NUMPAD8))
		{
			if (currentop == 1) Bottom(); else Up();
		}

		// Scroll down
		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_PAD_DOWN) || IsKeyJustUp(VK_NUMPAD2))
		{
			if (currentop == totalop) Top(); else Down();
		}

		// B press
		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_RRIGHT) || IsKeyJustUp(VK_NUMPAD0))
		{
			if (currentsub == SUB::MAINMENU) SetSub_closed(); else SetSub_previous();
		}

		// Binds press
		if (currentsub != SUB::MAINMENU && isBinds())
		{
			SetSub_closed();
		}
	}
	static void Up()
	{
		currentop--; currentop_w_breaks--;
		PlaySoundFrontend_default("NAV_UP_DOWN");
		breakscroll = 1;
	}
	static void Down()
	{
		currentop++; currentop_w_breaks++;
		PlaySoundFrontend_default("NAV_UP_DOWN");
		breakscroll = 2;
	}
	static void Bottom()
	{
		currentop = totalop; currentop_w_breaks = totalop;
		PlaySoundFrontend_default("NAV_UP_DOWN");
		breakscroll = 3;
	}
	static void Top()
	{
		currentop = 1; currentop_w_breaks = 1;
		PlaySoundFrontend_default("NAV_UP_DOWN");
		breakscroll = 4;
	}
	static void SetSub_previous()
	{
		currentsub = currentsub_ar[currentsub_ar_index]; // Get previous submenu from array and set as current submenu
		currentop = currentop_ar[currentsub_ar_index]; // Get last selected option from array and set as current selected option
		currentsub_ar_index--; // Decrement array index by 1
		printingop = 0; // Reset option print variable
		PlaySoundFrontend_default("BACK"); // Play sound
	}
	static void SetSub_new(int sub_index)
	{
		currentsub_ar_index++; // Increment array index
		currentsub_ar[currentsub_ar_index] = currentsub; // Store current submenu index in array
		currentsub = sub_index; // Set new submenu as current submenu (Static_1)

		currentop_ar[currentsub_ar_index] = currentop; // Store currently selected option in array
		currentop = 1; currentop_w_breaks = 1; // Set new selected option as first option in submenu

		printingop = 0; // Reset currently printing option var
	}
	static void SetSub_closed()
	{
		ENABLE_ALL_CONTROL_ACTIONS(2);
		PlaySoundFrontend_default("BACK");
		currentsub = SUB::CLOSED;
	}

}; unsigned __int16 menu::currentsub = 0; unsigned __int16 menu::currentop = 0; unsigned __int16 menu::currentop_w_breaks = 0; unsigned __int16 menu::totalop = 0; unsigned __int16 menu::printingop = 0; unsigned __int16 menu::breakcount = 0; unsigned __int16 menu::totalbreaks = 0; unsigned __int8 menu::breakscroll = 0; __int16 menu::currentsub_ar_index = 0; int menu::currentsub_ar[20] = {}; int menu::currentop_ar[20] = {}; int menu::SetSub_delayed = 0; unsigned long int menu::livetimer;
bool CheckAJPressed()
{
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_SCRIPT_RDOWN) || IsKeyJustUp(VK_NUMPAD5)) return true; else return false;
}
bool CheckRPressed()
{
	if (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RIGHT) || IsKeyDown(VK_NUMPAD6)) return true; else return false;
}
bool CheckRJPressed()
{
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RIGHT) || IsKeyJustUp(VK_NUMPAD6)) return true; else return false;
}
bool CheckLPressed()
{
	if (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LEFT) || IsKeyDown(VK_NUMPAD4)) return true; else return false;
}
bool CheckLJPressed()
{
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LEFT) || IsKeyJustUp(VK_NUMPAD4)) return true; else return false;
}
bool IsOptionPressed()
{
	if (CheckAJPressed())
	{
		PlaySoundFrontend_default("SELECT");
		return true;
	}
	else return false;
}
bool IsOptionRPressed()
{
	if (CheckRPressed())
	{
		PlaySoundFrontend_default("NAV_LEFT_RIGHT");
		return true;
	}
	else return false;
}
bool IsOptionRJPressed()
{
	if (CheckRJPressed())
	{
		PlaySoundFrontend_default("NAV_LEFT_RIGHT");
		return true;
	}
	else return false;
}
bool IsOptionLPressed()
{
	if (CheckLPressed())
	{
		PlaySoundFrontend_default("NAV_LEFT_RIGHT");
		return true;
	}
	else return false;
}
bool IsOptionLJPressed()
{
	if (CheckLJPressed())
	{
		PlaySoundFrontend_default("NAV_LEFT_RIGHT");
		return true;
	}
	else return false;
}
void AddTitle(char* text)
{
	setupdraw();
	SET_TEXT_FONT(font_title);

	SET_TEXT_COLOUR(titletext.R, titletext.G, titletext.B, titletext.A);
	SET_TEXT_CENTRE(1);

	if (Check_compare_string_length(text, 14))
	{
		SET_TEXT_SCALE(0.75f, 0.75f);
		drawstring(text, 0.16f + menuPos, 0.1f);
	}
	else drawstring(text, 0.16f + menuPos, 0.13f);


}
void nullFunc(){ return; }
void AddOption(char* text, bool &option_code_bool = null, void (&Func)() = nullFunc, int submenu_index = -1)
{
	char* tempChar;
	if (font_options == 2 || font_options == 7) tempChar = "  ------"; // Font unsafe
	else tempChar = "  ~b~>"; // Font safe

	if (menu::printingop + 1 == menu::currentop && (font_selection == 2 || font_selection == 7)) tempChar = "  ------"; // Font unsafe
	else tempChar = "  ~b~>"; // Font safe

	menu::printingop++;

	OptionY = 0.0f;
	if (menu::currentop <= 14)
	{
		if (menu::printingop > 14) return;
		else OptionY = ((float)(menu::printingop) * 0.035f) + 0.125f;
	}
	else
	{
		if (menu::printingop < (menu::currentop - 13) || menu::printingop > menu::currentop) return;
		else OptionY = ((float)(menu::printingop - (menu::currentop - 14))* 0.035f) + 0.125f;
	}

	setupdraw();
	SET_TEXT_FONT(font_options);
	SET_TEXT_COLOUR(optiontext.R, optiontext.G, optiontext.B, optiontext.A);
	if (menu::printingop == menu::currentop)
	{
		SET_TEXT_FONT(font_selection);
		SET_TEXT_COLOUR(selectedtext.R, selectedtext.G, selectedtext.B, selectedtext.A);
		if (IsOptionPressed())
		{
			if (&option_code_bool != &null) option_code_bool = true;
			Func();
			if (submenu_index != -1) menu::SetSub_delayed = submenu_index;
		}
	}

	if (submenu_index != -1) text = AddStrings(text, tempChar);
	if (menuPos == 0.34f)
	{
		SET_TEXT_CENTRE(1);
		drawstring(text, 5.0f, OptionY);
	}
	else drawstring(text, 0.066f + menuPos, OptionY);
}
void OptionStatus(int status)
{
	if (OptionY < 0.6325f && OptionY > 0.1425f)
	{
		char* tempChar;
		SET_TEXT_FONT(4);
		SET_TEXT_SCALE(0.34f, 0.34f);
		SET_TEXT_CENTRE(1);

		if (status == 0){
			SET_TEXT_COLOUR(255, 102, 102, 250); //RED
			tempChar = "OFF";
		}
		else if (status == 1){
			SET_TEXT_COLOUR(102, 255, 102, 250); //GREEN
			tempChar = "ON";
		}
		else{
			SET_TEXT_COLOUR(255, 255, 102, 250); //YELLOW
			tempChar = "??";
		}

		drawstring(tempChar, 0.233f + menuPos, OptionY);

	}
}
void AddToggle(char* text, bool &loop_variable, bool &extra_option_code_ON = null, bool &extra_option_code_OFF = null)
{
	AddOption(text);

	if (menu::printingop == menu::currentop){ if (IsOptionPressed()){
			loop_variable = !loop_variable;
			if (loop_variable && &extra_option_code_ON != &null) extra_option_code_ON = true;
			else if (!loop_variable && &extra_option_code_OFF != &null) extra_option_code_OFF = true;
		}}

	if (!loop_variable) OptionStatus(0); // Display OFF
	else if (loop_variable) OptionStatus(1); // Display ON
}
void AddLocal(char* text, Void condition, bool &option_code_ON, bool &option_code_OFF)
{
	AddOption(text);
	if (menu::printingop == menu::currentop){ if (IsOptionPressed()){
			if (condition == 0 && &option_code_ON != &null) option_code_ON = true;
			else if (condition != 0 && &option_code_OFF != &null) option_code_OFF = true;
		}}

	if (!condition) OptionStatus(0); // Display OFF
	else if (condition) OptionStatus(1); // Display ON
}
void AddBreak(char* text)
{
	menu::printingop++; menu::breakcount++; 

	OptionY = 0.0f;
	if (menu::currentop <= 14)
	{
		if (menu::printingop > 14) return;
		else OptionY = ((float)(menu::printingop) * 0.035f) + 0.125f;
	}
	else
	{
		if (menu::printingop < (menu::currentop - 13) || menu::printingop > menu::currentop) return;
		else OptionY = ((float)(menu::printingop - (menu::currentop - 14))* 0.035f) + 0.125f;
	}

	setupdraw();
	SET_TEXT_FONT(font_breaks);
	SET_TEXT_COLOUR(optionbreaks.R, optionbreaks.G, optionbreaks.B, optionbreaks.A);
	if (menu::printingop == menu::currentop)
	{
		switch (menu::breakscroll)
		{
		case 1:
			menu::currentop_w_breaks = menu::currentop_w_breaks + 1;
			menu::currentop--; break;
		case 2:
			menu::currentop_w_breaks = menu::currentop - menu::breakcount;
			menu::currentop++; break;
		case 3:
			menu::currentop_w_breaks = menu::totalop - (menu::totalbreaks - 1);
			menu::currentop--; break;
		case 4:
			menu::currentop_w_breaks = 1;
			menu::currentop++; break;
		}
		
	}
	if (menuPos == 0.34f)
	{
		drawstring(text, 0.066f + menuPos, OptionY);
	}
	else
	{
		SET_TEXT_CENTRE(1);
		drawstring(text, 0.16f + menuPos, OptionY);
	}

}
void AddNumber(char* text, long value, __int8 decimal_places, bool &A_PRESS = null, bool &RIGHT_PRESS = null, bool &LEFT_PRESS = null)
{
	AddOption(text, null);

	if (OptionY < 0.6325 && OptionY > 0.1425)
	{
		SET_TEXT_FONT(0);
		SET_TEXT_SCALE(0.3f, 0.3f);
		SET_TEXT_CENTRE(1);

		drawfloat(value, (DWORD)decimal_places, 0.233f + menuPos, OptionY);
	}

	if (menu::printingop == menu::currentop)
	{
		if (IsOptionPressed() && &A_PRESS != &null) *&A_PRESS = true;
		else if (IsOptionRJPressed() && &RIGHT_PRESS != &null) RIGHT_PRESS = true;
		else if (IsOptionRPressed() && &RIGHT_PRESS != &null) RIGHT_PRESS = true;
		else if (IsOptionLJPressed() && &LEFT_PRESS != &null) LEFT_PRESS = true;
		else if (IsOptionLPressed() && &LEFT_PRESS != &null) LEFT_PRESS = true;

	}

}
void AddTele(char* text, float X, float Y, float Z, bool &extra_option_code = null)
{
	AddOption(text, null);
	if (menu::printingop == menu::currentop)
	{
		if (IsOptionPressed())
		{
			if (!Check_self_in_vehicle())
			{
				SET_ENTITY_COORDS(PLAYER_PED_ID(), X, Y, Z, 0, 0, 0, 1);
			}
			else
			{
				RequestControlOfEnt(myVeh);
				SET_ENTITY_COORDS(myVeh, X, Y, Z, 0, 0, 0, 1);
			}
			LOAD_ALL_OBJECTS_NOW();
			if (&extra_option_code != &null) extra_option_code = true;
		}
	}

}


// Hax functions:
void set_massacre_mode()
{
	float tempCoords1[3];
	DWORD tempHash;
	DWORD tempPed = PLAYER_PED_ID();
	DWORD tempVehicle;
	bool tick = 0;

	offset_from_entity(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);

	// Kick away naughty players
	for (int i = 0; i <= 29; i++)
	{
		if (IS_PLAYER_TARGETTING_ENTITY(i, tempPed) || IS_PLAYER_FREE_AIMING_AT_ENTITY(i, tempPed))
		{
			if (!tick)
			{
				PrintStringBottomCentre("~h~You~s~ are being aimed at. Taking care of it!");
				tick = true;
			}
			APPLY_FORCE_TO_ENTITY(GET_PLAYER_PED(i), 1, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 1, 1, 1, 1, 0, 1);
		}
	}

	// Kick away nearest vehicle
	tempVehicle = GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 400.0f, 0, 4);
	if (DOES_ENTITY_EXIST(tempVehicle)) APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);

	// Exploding vehicles
	switch (GET_RANDOM_INT_IN_RANGE(1, 10))
	{
	case 1: tempHash = 3945366167; break;
	case 2: tempHash = 92612664; break;
	case 3: tempHash = 1488164764; break;
	case 4: tempHash = 117401876; break;
	case 5: tempHash = 408192225; break;
	case 6: tempHash = 3863274624; break;
	case 7: tempHash = 165154707; break;
	case 8: tempHash = 1011753235; break;
	case 9: tempHash = 941800958; break;
	case 10: tempHash = 970385471; break;
	}

	tempVehicle = CREATE_VEHICLE(tempHash, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
	APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
	NETWORK_EXPLODE_VEHICLE(tempVehicle, 1, 1, 1);

	// Dying peds
	switch (GET_RANDOM_INT_IN_RANGE(1, 10))
	{
	case 1: tempHash = 1682622302; break;
	case 2: tempHash = 113504370; break;
	case 3: tempHash = 4244282910; break;
	case 4: tempHash = 808859815; break;
	case 5: tempHash = 1004114196; break;
	case 6: tempHash = 3696858125; break;
	case 7: tempHash = 921110016; break;
	case 8: tempHash = 880829941; break;
	case 9: tempHash = 1462895032; break;
	case 10: tempHash = 773063444; break;
	}

	offset_from_entity(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
	tempPed = CREATE_PED(22, tempHash, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
	APPLY_FORCE_TO_ENTITY(tempPed, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
	EXPLODE_PED_HEAD(tempPed, 324506233);
	ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 26, 4.0f, 1, 0, 3.0f);

	// Water hydrants
	offset_from_entity(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
	ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 13, 8.0f, 1, 0, 3.0f);

	// Zombies
	offset_from_entity(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
	tempPed = CREATE_PED(22, -1404353274, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
	PED_TO_NET(tempPed);
	SET_PED_COMBAT_ABILITY(tempPed, 100);
	TASK_COMBAT_HATED_TARGETS_AROUND_PED(tempPed, 400.0f, 0);
}
void sample_createEscort()
{
	if (!IS_WAYPOINT_ACTIVE()) PrintStringBottomCentre("~r~Error:~s~ No waypoint set.");
	else
	{
		float Pos[3];
		Vector3 Coord = GET_BLIP_COORDS(GET_FIRST_BLIP_INFO_ID(_GET_BLIP_INFO_ID_ITERATOR()));
		GET_GROUND_Z_FOR_3D_COORD(Coord.x, Coord.y, Coord.z, &Coord.z);
		VectorToFloat(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER_PED_ID(), 0.0f, 5.0f, 1.0f), Pos);
		WAIT(10);
		DWORD tempPed = CREATE_PED(1, GET_HASH_KEY("A_C_CHIMP"), Pos[0], Pos[1], Pos[2], 0.0f, 1, 1);
		DWORD tempVehicle = CREATE_VEHICLE(GET_HASH_KEY("KURUMA2"), Pos[0], Pos[1], Pos[2] + 2.0f, GET_ENTITY_HEADING(PLAYER_PED_ID()), 1, 1);
		RequestControlOfEnt(tempVehicle);
		SET_VEHICLE_COLOURS(tempVehicle, 0, 0);
		SET_VEHICLE_NUMBER_PLATE_TEXT(tempVehicle, (DWORD*)"VIP");
		for (int i = -1; i <= 20; i++)
		{
			if (!IS_VEHICLE_SEAT_FREE(tempVehicle, i)) continue;
			TASK_WARP_PED_INTO_VEHICLE(PLAYER_PED_ID(), tempVehicle, i); break;
		}
		TASK_VEHICLE_MISSION_COORS_TARGET(tempPed, tempVehicle, Coord.x, Coord.y, Coord.z, 4, 20.0f, 786469, 20.0f, 10.0f, 1);
	}
}
DWORD grav_partfx, grav_entity; bool grav_toggled = 0, grav_target_locked = 0;
Vector3 get_coords_from_cam(float distance)
{
	Vector3 Rot = GET_GAMEPLAY_CAM_ROT(2);
	static Vector3 Coord = GET_GAMEPLAY_CAM_COORD();

	Rot.y = distance * cos(Rot.x);
	Coord.x = Coord.x + Rot.y * sin(Rot.z * -1.0f);
	Coord.y = Coord.y + Rot.y * cos(Rot.z * -1.0f);
	Coord.z = Coord.z + distance * sin(Rot.x);

	return Coord;
}
void set_gravity_gun()
{
	DWORD tempPed, tempWeap;

	if (!grav_target_locked) GET_PLAYER_TARGET_ENTITY(PLAYER_ID(), &grav_entity);

	tempPed = PLAYER_ID(); GET_CURRENT_PED_WEAPON(PLAYER_PED_ID(), &tempWeap, 1);
	if ((IS_PLAYER_FREE_AIMING(tempPed) || IS_PLAYER_TARGETTING_ANYTHING(tempPed)) && DOES_ENTITY_EXIST(grav_entity) && tempWeap == 453432689)
	{
		if (!grav_target_locked) GET_PLAYER_TARGET_ENTITY(PLAYER_ID(), &grav_entity); grav_target_locked = true;
		float Coord[3]; VectorToFloat(get_coords_from_cam(5.5f), Coord);

		if (!DOES_PARTICLE_FX_LOOPED_EXIST(grav_partfx))
		{
			REQUEST_PTFX_ASSET();
			if (HAS_PTFX_ASSET_LOADED())
			{
				grav_partfx = START_PARTICLE_FX_LOOPED_AT_COORD((DWORD*)"scr_drug_traffic_flare_L", Coord[0], Coord[1], Coord[2], 0.0f, 0.0f, 0.0f, 0.5f, 0, 0, 0, 0);
				SET_PARTICLE_FX_LOOPED_COLOUR(grav_partfx, 1.0f, 0.84f, 0.0f, 0);
			}
		}

		//RequestControlOfid(NETWORK_GET_NETWORK_ID_FROM_ENTITY(grav_entity));
		RequestControlOfEnt(grav_entity);
		SET_ENTITY_COORDS_NO_OFFSET(grav_entity, Coord[0], Coord[1], Coord[2], 0, 0, 0);
		if (IS_ENTITY_A_VEHICLE(grav_entity)) SET_ENTITY_HEADING(grav_entity, GET_ENTITY_HEADING(PLAYER_PED_ID()) + 90.0f);

		if (IS_PED_SHOOTING(PLAYER_PED_ID()))
		{
			PLAY_SOUND_FROM_ENTITY(-1, (DWORD*)"Foot_Swish", grav_entity, (DWORD*)"docks_heist_finale_2a_sounds", 0, 0);
			SET_ENTITY_HEADING(grav_entity, GET_ENTITY_HEADING(PLAYER_PED_ID()) + 90.0f);
			APPLY_FORCE_TO_ENTITY(grav_entity, 1, 350.0f, 0.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
			grav_target_locked = false;
		}
	}
	else if (DOES_PARTICLE_FX_LOOPED_EXIST(grav_partfx))
	{
		STOP_PARTICLE_FX_LOOPED(grav_partfx, 0);
		REMOVE_PARTICLE_FX(grav_partfx, 0);
		REMOVE_PTFX_ASSET();
	}
	if (!IS_PLAYER_FREE_AIMING_AT_ENTITY(tempPed, grav_entity) || !IS_PLAYER_TARGETTING_ENTITY(tempPed, grav_entity)) grav_target_locked = false;

}
void set_gta2_cam_rot()
{
	Vector3 Rot = GET_GAMEPLAY_CAM_ROT(2);
	if (!Check_self_in_vehicle()){
		SET_ENTITY_ROTATION(PLAYER_PED_ID(), Rot.x, Rot.y, Rot.z, 2, 1);
	}
	else{
		SET_ENTITY_ROTATION(myVeh, Rot.x, Rot.y, Rot.z, 2, 1);
	}
}


}



namespace sub{
	// Define submenus here.
void MainMenu()
{
	AddTitle("Menya Baes");
	AddOption("Sample Submenu", null, nullFunc, SUB::SAMPLE);
	AddOption("Large Submenu", null, nullFunc, SUB::YOURSUB);
	AddOption("Settings", null, nullFunc, SUB::SETTINGS);

	if (menujustopened)
	{
		PrintBottomLeft(AddStrings("Menya Base by ", "MAFINS.")); // Your opening message goes here.
		menujustopened = false;
	}
}

void Settings()
{
	bool menu_pos_plus = 0, menu_pos_minus = 0;

	AddTitle("Settings");
	AddOption("Menu Colours", null, nullFunc, SUB::SETTINGS_COLOURS);
	AddOption("Menu Fonts", null, nullFunc, SUB::SETTINGS_FONTS);
	AddNumber("Menu Position", (DWORD)menuPos / 100, 0, null, menu_pos_plus, menu_pos_minus);


	if (menu_pos_plus){
		if (menuPos < 0.68f) menuPos += 0.01f;
		return;
	}
	else if (menu_pos_minus){
		if (menuPos > 0.0f) menuPos -= 0.01f;
		return;
	}
}
void AddsettingscolOption(char* text, unsigned __int8 submenu_index, int index)
{
	AddOption(text, null, nullFunc, submenu_index);

	if (menu::printingop == menu::currentop)
	{
		switch (index)
		{
			// Colours
		case COL::TITLEBOX:
			settings_rgba = &titlebox; break;
		case COL::BACKGROUND:
			settings_rgba = &BG; break;
		case COL::TITLETEXT:
			settings_rgba = &titletext; break;
		case COL::OPTIONTEXT:
			settings_rgba = &optiontext; break;
		case COL::OPTIONCOUNT:
			settings_rgba = &optioncount; break;
		case COL::SELECTEDTEXT:
			settings_rgba = &selectedtext; break;
		case COL::BREAKS:
			settings_rgba = &optionbreaks; break;
		case COL::SELECTIONHIGH:
			settings_rgba = &selectionhi; break;

			// Fonts
		case FON::TITLE:
			settings_font = &font_title; break;
		case FON::OPTION:
			settings_font = &font_options; break;
		case FON::SELECTEDTEXT:
			settings_font = &font_selection; break;
		case FON::BREAKS:
			settings_font = &font_breaks; break;
		}
	}
}
void SettingsColours()
{
	AddTitle("Menu Colours");
	AddsettingscolOption("Title Box", SUB::SETTINGS_COLOURS2, COL::TITLEBOX);
	AddsettingscolOption("Background", SUB::SETTINGS_COLOURS2, COL::BACKGROUND);
	AddsettingscolOption("Title Text", SUB::SETTINGS_COLOURS2, COL::TITLETEXT);
	AddsettingscolOption("Option Text", SUB::SETTINGS_COLOURS2, COL::OPTIONTEXT);
	AddsettingscolOption("Selected Text", SUB::SETTINGS_COLOURS2, COL::SELECTEDTEXT);
	AddsettingscolOption("Option Breaks", SUB::SETTINGS_COLOURS2, COL::BREAKS);
	AddsettingscolOption("Option Count", SUB::SETTINGS_COLOURS2, COL::OPTIONCOUNT);
	AddsettingscolOption("Selection Box", SUB::SETTINGS_COLOURS2, COL::SELECTIONHIGH);
	AddToggle("Rainbow", loop_RainbowBoxes);
}
void SettingsColours2()
{
	bool settings_r_input = 0, settings_r_plus = 0, settings_r_minus = 0;
	int *settings_rgba2;

	AddTitle("Set Colour");
	AddNumber("Red", settings_rgba->R, 0, settings_r_input, settings_r_plus, settings_r_minus);
	AddNumber("Green", settings_rgba->G, 0, settings_r_input, settings_r_plus, settings_r_minus);
	AddNumber("Blue", settings_rgba->B, 0, settings_r_input, settings_r_plus, settings_r_minus);
	AddNumber("Opacity", settings_rgba->A, 0, settings_r_input, settings_r_plus, settings_r_minus);

	switch (menu::currentop)
	{
	case 1: settings_rgba2 = &settings_rgba->R; break;
	case 2: settings_rgba2 = &settings_rgba->G; break;
	case 3: settings_rgba2 = &settings_rgba->B; break;
	case 4: settings_rgba2 = &settings_rgba->A; break;
	}

	if (settings_r_input){
		int tempHash = abs(StringToInt(keyboard()));
		if (!(tempHash >= 0 && tempHash <= 255)) PrintError_InvalidInput();
		else *settings_rgba2 = tempHash;
		return;
	}

	if (settings_r_plus){
		if (*settings_rgba2 < 255) (*settings_rgba2)++;
		else *settings_rgba2 = 0;
		return;
	}
	else if (settings_r_minus){
		if (*settings_rgba2 > 0) (*settings_rgba2)--;
		else *settings_rgba2 = 255;
		return;
	}
}
void AddsettingsfonOption(char* text, unsigned __int8 font_index)
{
	AddOption(text);

	if (menu::printingop == menu::currentop  &&  IsOptionPressed())
	{
		*settings_font = font_index;
	}
}
void SettingsFonts()
{
	AddTitle("Menu Fonts");
	AddsettingscolOption("Title", SUB::SETTINGS_FONTS2, FON::TITLE);
	AddsettingscolOption("Options", SUB::SETTINGS_FONTS2, FON::OPTION);
	AddsettingscolOption("Selected Option", SUB::SETTINGS_FONTS2, FON::SELECTEDTEXT);
	AddsettingscolOption("Option Breaks", SUB::SETTINGS_FONTS2, FON::BREAKS);
}
void SettingsFonts2()
{
	bool fonts2_input = 0;

	AddTitle("Set Font");
	AddsettingsfonOption("Normalish", 0);
	AddsettingsfonOption("Impactish", 4);
	AddsettingsfonOption("Italic", 1);
	AddsettingsfonOption("Pricedown", 7);
	AddsettingsfonOption("Caps", 2);
	AddOption("Input Index", fonts2_input);

	if (fonts2_input){
		int tempInt = abs(StringToInt(keyboard()));
		*settings_font = tempInt;
		return;
	}
}



void SampleSub()
{
	bool sample_mapmod = 0, hour_plus = 0, hour_minus = 0, timescale_plus = 0, timescale_minus = 0, sample_invisible = 0, sample_gravity_gun_on = 0,
	sample_gta2cam = 0;

	int sample_hour = GET_CLOCK_HOURS();

	AddTitle("SHRUNKEN TITLE FEATURE");

	AddBreak("---Map---");
	AddOption("Load Map Mod", sample_mapmod);
	AddTele("Teleport to Map Mod", 509.8423f, 5589.2422f, 792.0000f);

	AddBreak("---Weather---");
	AddNumber("Hour", GET_CLOCK_HOURS(), 0, null, hour_plus, hour_minus);
	AddNumber("Time Scale", current_timescale, 2, null, timescale_plus, timescale_minus);

	AddBreak("---Others---");
	AddLocal("Invisibility", !IS_ENTITY_VISIBLE(PLAYER_PED_ID()), sample_invisible, sample_invisible);
	AddToggle("Gravity Gun", loop_gravity_gun, sample_gravity_gun_on);
	AddToggle("GTA 2 Cam", loop_gta2cam, sample_gta2cam, sample_gta2cam);
	AddToggle("Massacre Mode", loop_massacre_mode);
	AddOption("Create Escort", null, sample_createEscort);

	AddBreak("---deez breaks r ugly---");


	if (sample_mapmod){
		Any tempHash = GET_HASH_KEY("prop_container_01a");
		PlaceObject(tempHash, 509.8423f, 5589.2422f, 791.0656f, 0.1410f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 520.5002f, 5584.3774f, 790.5033f, 5.4410f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 531.0571f, 5579.5405f, 788.6912f, 12.4410f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 541.3253f, 5574.8403f, 785.4896f, 19.4409f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 551.0662f, 5570.3701f, 780.7990f, 27.5407f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 560.1738f, 5566.2046f, 774.6979f, 35.0403f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 568.6718f, 5562.3198f, 767.4281f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 576.9716f, 5558.5269f, 759.5663f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 585.2493f, 5554.7471f, 751.7451f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 593.5072f, 5550.9722f, 743.9170f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 601.7770f, 5547.1912f, 736.0764f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 610.0651f, 5543.3994f, 728.2167f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 618.3337f, 5539.6226f, 720.3861f, 40.7936f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 626.6017f, 5535.8477f, 712.5473f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 634.8616f, 5532.0669f, 704.7252f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 643.1213f, 5528.2861f, 696.8940f, 40.7936f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 651.3914f, 5524.5059f, 689.0526f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 659.6512f, 5520.7275f, 681.2211f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 667.9110f, 5516.9424f, 673.3893f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 676.1708f, 5513.1670f, 665.5580f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 684.4307f, 5509.3789f, 657.7266f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 692.6906f, 5505.6079f, 649.9052f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 700.9504f, 5501.8271f, 642.0737f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 709.2201f, 5498.0464f, 634.2426f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 717.4602f, 5494.2759f, 626.4309f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 725.7202f, 5490.4980f, 618.5996f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 733.9800f, 5486.7226f, 610.7783f, 40.7396f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 742.5997f, 5482.7764f, 603.1669f, 36.9395f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 751.8304f, 5478.5518f, 596.3347f, 31.0392f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 761.7103f, 5474.0220f, 590.6132f, 24.5989f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 772.0702f, 5469.2827f, 586.0803f, 18.9288f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 782.8400f, 5464.3433f, 582.8604f, 11.5788f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 793.8899f, 5459.2847f, 581.1174f, 5.0787f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 805.1001f, 5454.1479f, 580.8762f, -2.5212f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 816.1702f, 5449.0796f, 581.9746f, -7.6213f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 827.1907f, 5444.0405f, 584.5823f, -16.6212f, 0.0f, 65.3998f);
		PlaceObject(tempHash, 837.6807f, 5439.2407f, 588.8990f, -24.4210f, 0.0f, 65.3998f);
		PrintBottomLeft(AddStrings("Hax by ~b~", "XBLToothpik"));
		return;
	}

	if (hour_plus){
		if (sample_hour + 1 == 24) NETWORK_OVERRIDE_CLOCK_TIME(0, 0, 0);
		else NETWORK_OVERRIDE_CLOCK_TIME((sample_hour + 1), 0, 0);
		return;
	}
	else if (hour_minus){
		if ((sample_hour - 1) == -1) NETWORK_OVERRIDE_CLOCK_TIME(23, 0, 0);
		else NETWORK_OVERRIDE_CLOCK_TIME((sample_hour - 1), 0, 0);
		return;
	}

	if (timescale_plus){
		if (current_timescale < 2.0f) current_timescale += 0.1f;
		SET_TIME_SCALE(current_timescale);
		return;
	}
	else if (timescale_minus){
		if (current_timescale > 0.0f) current_timescale -= 0.1f;
		SET_TIME_SCALE(current_timescale);
		return;
	}

	if (sample_invisible){
		if (IS_ENTITY_VISIBLE(PLAYER_PED_ID())) SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 0);
		else SET_ENTITY_VISIBLE(PLAYER_PED_ID(), 1);
		return;
	}

	if (sample_gravity_gun_on){
		PrintStringBottomCentre("Use Mr ~b~Pistol~s~ for Hax!");
		return;
	}

	if (sample_gta2cam){
		if (loop_gta2cam)
		{
			if (DOES_CAM_EXIST(cam_gta2)) SET_CAM_ACTIVE(cam_gta2, 1);
			else
			{
				cam_gta2 = CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
				ATTACH_CAM_TO_ENTITY(cam_gta2, PLAYER_PED_ID(), 0.0f, 0.0f, 8.5f, 1);
				Vector3 Pos = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
				POINT_CAM_AT_COORD(cam_gta2, Pos.x, Pos.y, -1000000);
				SET_CAM_ACTIVE(cam_gta2, 1);
			}
			RENDER_SCRIPT_CAMS(1, 0, 3000, 1, 0);
		}
		else if (DOES_CAM_EXIST(cam_gta2))
			{
				SET_CAM_ACTIVE(cam_gta2, 0);
				DESTROY_CAM(cam_gta2, 0);
				RENDER_SCRIPT_CAMS(0, 0, 3000, 1, 0);
			}
		return;
	}



}

void YourSub()

{
	// Initialise local variables here:
	bool print_deez_nuts = 0;
	char yourChar[10];

	// Options' text here:
	AddTitle("Timone n Pumba");
	for (int i = 0; i < 69; i++)
	{ sprintf_s(yourChar, "Option %i", i + 1); AddOption(yourChar, print_deez_nuts); }

	// Options' code here:
	if (print_deez_nuts)
	{
		PrintStringBottomCentre( AddStrings( AddInt_S( "Option ", menu::currentop ), " ~b~selected!" ) );
		return; // Either use return; to exit to the switch if you don't have code below that you want executed.
	}


}






}






void menu::loops()
{ 
	/*	Make calls to functions that you want looped over here, e.g. ambient lights, gravity gun, explosions, checks, etc.
		Can also be used for (bool) options that are to be executed from many parts of the script. */

	myVeh = GET_VEHICLE_PED_IS_IN(PLAYER_PED_ID(), 0); // Store current vehicle

	if (loop_massacre_mode) set_massacre_mode(); // Massacre mode

	if (loop_RainbowBoxes && GET_GAME_TIMER() >= livetimer)
	{	titlebox.R = RandomRGB(); titlebox.G = RandomRGB(); titlebox.B = RandomRGB();
		BG.R = RandomRGB(); BG.G = RandomRGB(); BG.B = RandomRGB();
		selectedtext.R = RandomRGB(); selectedtext.G = RandomRGB(); selectedtext.B = RandomRGB();
	};


	if (loop_gravity_gun) set_gravity_gun();

	if (loop_gta2cam) set_gta2_cam_rot();

}

void menu::submenu_switch()
{ // Make calls to submenus over here.

	switch (currentsub)
	{
	case SUB::MAINMENU:					sub::MainMenu(); break;
	case SUB::SETTINGS:					sub::Settings(); break;
	case SUB::SETTINGS_COLOURS:			sub::SettingsColours(); break;
	case SUB::SETTINGS_COLOURS2:		sub::SettingsColours2(); break;
	case SUB::SETTINGS_FONTS:			sub::SettingsFonts(); break;
	case SUB::SETTINGS_FONTS2:			sub::SettingsFonts2(); break;
	case SUB::SAMPLE:					sub::SampleSub(); break;
	case SUB::YOURSUB:					sub::YourSub(); break;
//	case SUB::NAME						sub::name(); break;

	}
}


void menu::sub_handler()
{
	if (currentsub == SUB::CLOSED){
		while_closed();
	}

	else{
		submenu_switch();
		if (SetSub_delayed != NULL)
		{
			SetSub_new(SetSub_delayed);
			SetSub_delayed = NULL;
		}

		while_opened();

		// 1.8s delay for rainbow related loops
		if (GET_GAME_TIMER() >= livetimer) livetimer = GET_GAME_TIMER() + 1800;
	}
}
void main()
{
	srand(GetTickCount());
	while (true)
	{
		WAIT(0);
		menu::base();
		menu::loops();
		menu::sub_handler();
	}
}


