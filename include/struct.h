/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** file 1
*/

#ifndef STRUCT
#define STRUCT

//elements
typedef struct element_s
{
    sfSprite *spr;
    sfTexture *tex;
    sfVector2f pos;
    sfIntRect rect;
} element_t;

//global structure
typedef struct struct_s
{
    sfRenderWindow *win;
    sfEvent evt;
    sfView *cam;
    sfView *mini_maps;
    sfView *hud;
    struct settings_s *settings;
    struct audio_s *audio;
    struct intro_s *intro;
    struct menu_s *menu;
    struct game_s *game;
}struct_t;

typedef enum inputs_type
{
    INPUT_UP,
    INPUT_DOWN,
    INPUT_LEFT,
    INPUT_RIGHT,
    INPUT_HIT_UP,
    INPUT_HIT_DOWN,
    INPUT_HIT_LEFT,
    INPUT_HIT_RIGHT,
    INPUT_BOW,
    INPUT_BOMB
}inputs_type;

typedef struct settings_s
{
    int resolution[2];
    int fullscreen;
    int fps;
    int bpp;
    int volume[2];
    sfVideoMode video_mode;
    void (*ptr[6])(struct_t *, char *);
    int is_modified;
    sfKeyCode inputs[10];
}settings_t;

//intro scene
typedef struct intro_s
{
    int wait;
    int state;
    int time;
    element_t *back;
    element_t *text;
}intro_t;

//main menu scene

typedef struct controls_s
{
    int selected;
    int lock;
    int movelock;
    sfVector2f pos[10];
    element_t *controls;
    element_t *select;
    char text[2];
    sfText *key[10];
    sfFont *font;
    int wait_inputs;
} controls_t;

typedef struct options_s
{
    int selected;
    int isfull;
    int isres;
    int issfx;
    int ismusic;
    int istuto;
    int lock;
    int movelock;
    sfVector2f pos[6];
    element_t *options;
    element_t *res;
    element_t *mus_bar;
    element_t *sfx_bar;
    element_t *full_on;
    element_t *select;
    element_t *tuto;
}option_t;

typedef struct menu_s
{
    int page;
    int selected;
    int lock;
    int movelock;
    sfVector2f pos[4];
    element_t *main;
    element_t *logo;
    element_t *menu;
    element_t *cont;
    element_t *select;
    option_t *opt;
    controls_t *contr;
}menu_t;

typedef struct pause_s
{
    int selected;
    sfVector2f pos[3];
    element_t *pause;
    element_t *select;
} pause_t;

typedef enum object_type
{
    OBJ_VOID = 1,
    OBJ_SPIKE,
    OBJ_ROCK,
    OBJ_FIRE,
    OBJ_POOP,
    OBJ_METAL,
    OBJ_KEY = 100,
    OBJ_BOMB,
    OBJ_COIN,
    OBJ_PNJ = 500,
    OBJ_MOB1,
    OBJ_MOB2,
    OBJ_MOB3,
    OBJ_MOB4
}object_type;

typedef struct object_s
{
    enum object_type id;
    element_t *obj;
    sfFloatRect hit_box;
    struct stats_s *stats;
    struct object_s *next;
}object_t;

typedef struct game_room_door_s
{
    element_t *back;
    element_t *plain;
    sfFloatRect hit_box;
    char direction;
    struct game_room_door_s *next;
}game_room_door_t;

typedef struct game_room_s
{
    int id;
    int seed;
    int hide;
    int lock;
    element_t *back;
    sfFloatRect hit_box_wall[4];
    sfFloatRect player_here;
    int nb_object;
    int nb_door;
    struct object_s *first_object;
    struct object_s *last_create;
    struct game_room_door_s *first_door;
    struct game_room_s *next;
} game_room_t;

typedef struct game_basement_s
{
    int level;
    int nb_room;
    char changin_room_pos;
    int changing_room;
    sfTime anim_changing_room;
    int changing_basement;
    sfVector2f zoom_basement;
    sfTime anim_changing_basement;
    game_room_t *first_room;
} game_basement_t;

typedef enum sound_type
{
    SOUND_CURSOR,
    SOUND_SELECT,
    SOUND_PAUSE,
    SOUND_ATTACK
}sound_type;

typedef enum music_type
{
    MUSIC_INTRO,
    MUSIC_MENU,
    MUSIC_TYPE1,
    MUSIC_TYPE2
}music_type;

typedef struct audio_s
{
    sfMusic *master_music[4];
    sfSound *master_sound[4];
    sfSoundBuffer *master_sound_buffer[4];
}audio_t;

typedef struct map_s
{
    char *str;
    element_t *back;
    sfFloatRect hit_box_wall[4];
}map_t;

typedef struct player_bomb_s
{
    element_t *bomb;
    sfTime countdown;
    sfVector2f pos;
}player_bomb_t;

typedef struct stats_s
{
    int def;
    int cur_hp;
    int max_hp;
    int extra_hp;
    float speed;
    float range;
    float atk;
    float atk_spd;
    float grace;
    int exp;
    int max_exp;
}stats_t;

typedef struct arrows_s
{
    int direct;
    element_t *arrow;
    sfFloatRect hit_box;
    sfVector2f origin;
    struct arrows_s *next;
}arrows_t;

typedef struct player_s
{
    int life;
    float speedx;
    float speedy;
    int key;
    int bomb;
    int money;
    int player_atk_type;
    int nb_atk;
    int room_id;
    int nb_arrows;
    int bow;
    sfTime cooldown;
    sfVector2f pos;
    sfIntRect rec;
    sfFloatRect hit_box;
    sfSprite *sprite;
    sfTexture *texture;
    struct stats_s *stats;
    struct player_bomb_s *player_bomb;
    struct arrows_s *player_arrows;
}player_t;

typedef struct game_clock_s
{
    sfClock *master_clock;
    sfTime previous_master_time;
    sfTime master_time;
    sfTime delta_time;
    sfTime anim_time;
    int time_freeze;
}game_clock_t;

typedef struct game_text_s
{
    sfText *text[3];
    element_t *back[3];
    sfText *stats[5];
    sfFont *font;
    sfSprite *hpbar;
    sfTexture *hp;
    sfIntRect rect;
}game_text_t;

typedef enum game_mode
{
    MODE_GAME,
    MODE_PAUSE,
    MODE_DEAD
}game_mode;

typedef struct dialogue_s
{
    sfText *text;
    sfFont *font;
    int pnj_txt;
    int lock;
    sfTime deltatime;
    object_t *last_call;
    game_room_t *last_room_call;
} dialogue_t;

typedef struct particles_s
{
    element_t *p;
    struct particles_s *next;
} particles_t;

typedef struct particles_handler_s
{
    sfTime time_smoke;
    int nb_smoke;
    struct particles_s *first_smoke;
}particles_handler_t;

typedef struct game_s
{
    int stop;
    enum game_mode mode;
    void (*inputs_ptr[10])(struct_t *, player_t *);
    float inputs_presed[10];
    struct game_clock_s *clock;
    struct player_s *player;
    struct game_basement_s *map;
    struct game_text_s *game_text;
    struct dialogue_s *dialogue;
    struct particles_handler_s *particles;
    pause_t *pause;
    int debug;
}game_t;

#endif /* !STRUCT */