/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** .h
*/

#ifndef RPG
#define RPG

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "my.h"
#include "struct.h"

// prototypes

//struct
void init_struct(struct_t *store);
void destroy_struct(struct_t *store);

//element
sfVector2f vec(int x, int y);
sfIntRect rect(int left, int top, int width, int height);
element_t *create_elem(char *filepath, sfVector2f pos, sfIntRect rect,
                        int scale);
void destroy_elem(element_t *obj);

//settings
void init_settings(struct_t *store);
void get_settings(struct_t *store);
void set_resolution(struct_t *store, char *buff);
void set_fullsreen(struct_t *store, char *buff);
void set_bpp(struct_t *store, char *buff);
void set_fps(struct_t *store, char *buff);
void set_master_volume(struct_t *store, char *buff);
void set_sound_volume(struct_t *store, char *buff);
void write_settings(struct_t *store);
void print_active_param(struct_t *store);
void change_fps(struct_t *store, int fps);
void change_master_vl(struct_t *store, int mode);
void change_sound_vl(struct_t *store, int mode);
void change_fullscreen(struct_t *store);
void change_resolution(struct_t *store, int mode);
void apply_settings(struct_t *store);
void print_active_param(struct_t *store);
void get_inputs(struct_t *store);
void write_inputs(struct_t *store);
void change_inputs(struct_t *store, unsigned int select, unsigned int input);

//main sfView
sfView *load_cam(void);
sfView *set_camera_size(sfView *cam);
void load_mini_maps(struct_t *store);
void load_hud(struct_t *store);
void trans_view_room(struct_t *store, char d);
void change_basement_anim(struct_t *store);
void change_basement(struct_t *store);
void trans_view_basement_zoom(struct_t *store);
void trans_view_basement_unzoom(struct_t *store);

//intro
void init_intro(struct_t *store);
void destroy_intro(struct_t *store);
void intro(struct_t *store);
void clock_intro(game_clock_t *clock, struct_t *store);

//init_menu
void init_menu_cont(struct_t *store);
void init_menu_opt(struct_t *store);
void init_menu_main(struct_t *store);
void init_settings_values(struct_t *store);
void init_menu(struct_t *store);

//destroy_menu
void destroy_menu_cont(controls_t *cont);
void destroy_menu_opt(option_t *opt);
void destroy_menu(struct_t *store);

//menu
void menu_draw_settings(struct_t *store);
void menu(struct_t *store);

//menu event
void menu_main(struct_t *store);
void menu_pars_pages_for(struct_t *store, sfEvent evt, sfKeyCode key);
void menu_pars_pages(struct_t *store, sfEvent evt, sfKeyCode key);
void menu_mouse_selecter(struct_t *store, sfEvent evt);
void menu_selecter(struct_t *store, sfEvent evt, sfKeyCode key);
void menu_event(struct_t *store);

//menu options
void menu_opt_lock(struct_t *store);
void menu_opt_pars(struct_t *store);
void menu_opt_mouse_selecter(struct_t *store, sfEvent evt, option_t *opt);
void menu_opt_selecter(struct_t *store, sfEvent evt, sfKeyCode key,
                    option_t *opt);
void menu_opt_pars_pages(struct_t *store, sfEvent evt, option_t *opt);

//menu options modifiers
void menu_opt_sound_mod(struct_t *store, int type, int mod);
void menu_opt_music(struct_t *store, sfEvent evt);
void menu_opt_sound(struct_t *store, sfEvent evt);
void menu_opt_res(struct_t *store, sfEvent evt, option_t *opt);
void menu_opt_fullscreen(struct_t *store, sfEvent evt, option_t *opt);

//menu options controls
void wait_inputs(struct_t *store);
void menu_contr_selecter(struct_t *store, sfEvent evt);

//audio
void init_audio(struct_t *store);
void destroy_audio(struct_t *store);
void audio_run_sound(struct_t *store, sound_type type);
void audio_run_music(struct_t *store, music_type type);
void menu_audio(struct_t *store, int type);
void intro_audio(struct_t *store, int type);
void game_audio(struct_t *store, int type);

//dialogue
void init_dialogue(struct_t *store);
void destroy_dialogue(struct_t *store);
void set_pnj_txt(struct_t *store, object_t *tmp2_ptr, game_room_t *tmp_ptr);
void diag_time_out(struct_t *store);

//game
void switch_game_scene(struct_t *store);
void init_game(struct_t *store);
void destroy_game(struct_t *store);
void game_loop(struct_t *store);
void display_game(struct_t *store);
void display_game_hud(struct_t *store);
void obj_move(struct_t *store);
void mob_move_all(struct_t *store, object_t *mob);
void show_hitbox(struct_t *store, sfFloatRect rect);
void intro_loop(struct_t *store);
void init_hud(struct_t *store);
void init_particles(struct_t *store);
void destroy_particles(struct_t *store);
void destroy_hud(struct_t *store);
void update_txt_stats(int type, sfText *text, char *str);
int get_hitbox(struct_t *store, sfFloatRect tmp);
int mob_hitbox(struct_t *store, sfFloatRect tmp, object_t *mob);


//player
void init_player(struct_t *store);
void destroy_player(struct_t *store);
void player_events(struct_t *store);
void player_move(struct_t *store, player_t *player);
void player_move_up(struct_t *store, player_t *player);
void player_move_down(struct_t *store, player_t *player);
void player_move_left(struct_t *store, player_t *player);
void player_move_right(struct_t *store, player_t *player);
void player_fire_up(struct_t *store, player_t *player);
void player_fire_down(struct_t *store, player_t *player);
void player_fire_left(struct_t *store, player_t *player);
void player_fire_right(struct_t *store, player_t *player);

int arrow_hitbox(struct_t *store, sfFloatRect tmp);
int arrow_get_obj(struct_t *store, game_room_t *tmp_ptr, object_t *tmp2_ptr);

void player_bow(struct_t *store, player_t *player);
void player_bomb(struct_t *store, player_t *player);
void change_view(struct_t *store, int x, int y);
int player_get_obj(struct_t *store, game_room_t *tmp_ptr, object_t *tmp2_ptr);
void player_move_room(struct_t *store, game_room_t *tmp_ptr
                    , game_room_door_t *door);
void update_txt_inv(int type, sfText *text);
arrows_t *add_arrows(struct_t *store, arrows_t *p, sfVector2f pos);
void remove_arrows(player_t *player, arrows_t *p);
void remove_all_arrows(player_t *player);
void display_health(struct_t *store, game_text_t *hud);
void init_fly_obj(object_t *p, sfVector2f pos);
void init_spider_obj(object_t *p, sfVector2f pos);
void init_gaper_obj(object_t *p, sfVector2f pos);
void level_up(struct_t *store);
void heal_player(struct_t *store);
void hit_with_sword(struct_t *store, player_t *player);
void get_player_next_pos(struct_t *store, player_t *player, float posy);

//bomb
void bomb_explode(struct_t *store, player_t *player);
void create_smoke(struct_t *store, sfVector2f pos);
void display_smoke(struct_t *store);
void destroy_smoke(struct_t *store);
void damage_player(struct_t *store, player_t *player, int amount);
int in_range(sfVector2f center, int radius, sfVector2f target);
void destroy_rocks(struct_t *store, player_t *player);
void change_obj_exploded(object_t *obj);
void change_obj_fire(object_t *obj);
void hurt_mob(struct_t *store, game_room_t *room, object_t *mob);


//map
void init_map(struct_t *store);
void read_map(char *filepath, game_room_t *room);
void destroy_map(struct_t *store);
game_room_t *add_room(struct_t *store, game_room_t *p
                    , sfVector2f pos, void *seed);
void remove_room_link(struct_t *store, game_room_t *p);
void remove_all_room(struct_t *store);
void init_spawn_room(game_room_t *p, sfVector2f pos);
void init_basic_room(game_room_t *p, sfVector2f pos);
void init_special_room(game_room_t *p, sfVector2f pos);
void init_item_room(game_room_t *p, sfVector2f pos);
void init_boss_room(game_room_t *p, sfVector2f pos);
void init_zelda_room(game_room_t *p, sfVector2f pos);
object_t *add_room_object(game_room_t *room, object_t *p
                    , sfVector2f pos, void *seed);
void remove_room_object_link(object_t *p, game_room_t *room);
void init_void_obj(object_t *p, sfVector2f pos);
void init_spike_obj(object_t *p, sfVector2f pos);
void init_rock_obj(object_t *p, sfVector2f pos);
void init_fire_obj(object_t *p, sfVector2f pos);
void init_poop_obj(object_t *p, sfVector2f pos);
void init_metal_obj(object_t *p, sfVector2f pos);
void init_key_obj(object_t *p, sfVector2f pos);
void init_bomb_obj(object_t *p, sfVector2f pos);
void init_coin_obj(object_t *p, sfVector2f pos);
void init_pnj_obj(object_t *p, sfVector2f pos);
void init_zelda_obj(object_t *p, sfVector2f pos);
void remove_spe_obj(object_t *p, game_room_t *room);
game_room_door_t *add_room_door(game_room_t *room, game_room_door_t *p
                    , sfVector2f pos, void *seed);
void remove_room_door_link(game_room_door_t *p, game_room_t *room);
void init_up_door(game_room_door_t *p, sfVector2f pos);
void init_down_door(game_room_door_t *p, sfVector2f pos);
void init_left_door(game_room_door_t *p, sfVector2f pos);
void init_right_door(game_room_door_t *p, sfVector2f pos);
void create_door(struct_t *store);
void change_basement(struct_t *store);
void create_level(struct_t *store);
void door_handler(game_room_t *tmp
                , game_room_door_t *tmp3, int mob);


//pause
void display_pause(sfRenderWindow *win, struct_t *store);
void pause_parser(struct_t *store);
void pause_selecter(struct_t *store);
void pause_event(struct_t *store);
void pause_mode(struct_t *store);

//clock
void init_clock(game_t *game);
void destroy_clock(game_clock_t *clock);
void timer(struct_t *store);

//anim
void anim_obj(struct_t *store);
void anim_gaper(object_t *mob);
void anim_spider(object_t *mob);
void anim_fly(object_t *mob);
void anim_zelda(object_t *mob);

//calcul
float get_distance(struct_t *store, float speed);

#endif /* !RPG */