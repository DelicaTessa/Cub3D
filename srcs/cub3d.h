/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 11:03:45 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/04 19:38:40 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef	struct	s_img
{
	void		*cont;
	char		*addr;
	int			bits_per_pixel;
	int			line_bytes;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef	struct	s_move
{
	double		newpos_x;
	double		newpos_y;
	double		movspeed;
	double		dir;
	double		strafe;
	double		ccw;
	double		rotspeed;
	double		previous_x;
	int			ver;
	int			hor;
	int			rotdir;
}				t_move;

typedef	struct	s_texture
{
	t_img		ntext;
	void		*north;
	t_img		stext;
	void		*south;
	t_img		wtext;
	void		*west;
	t_img		etext;
	void		*east;
	t_img		sptext;
	void		*sprite;
}				t_texture;

typedef	struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;

typedef	struct	s_spr
{
	t_img	*spr_img;
	double	depth;
	double	height;
	double	width;
	int		mid;
	int		ystart;
	int		yend;
	int		xstart;
	int		xend;
	int		tx;
	int		ty;
	int		color;
}				t_spr;

typedef	struct	s_ray
{
	double		player_xpos;
	double		player_ypos;
	double		player_xdir;
	double		player_ydir;
	double		xplane;
	double		yplane;
	double		cam_x;
	double		ray_xdir;
	double		ray_ydir;
	double		ver;
	double		hor;
	double		vert_delta;
	double		hor_delta;
	double		len;
	int			ray_xpos;
	int			ray_ypos;
	int			stepx;
	int			stepy;
	int			hit;
	int			dir;
}				t_ray;

typedef	struct	s_map
{
	struct s_map		*copy;
	struct s_sprite		*sprites;
	int					bitmap;
	int					error;
	int					fd;
	int					spritecount;
	int					fr;
	int					fg;
	int					fb;
	int					cr;
	int					cg;
	int					cb;
	int					col;
	int					posy;
	int					posx;
	int					start;
	int					rows;
	unsigned long		res;
	long				height;
	long				width;
	double				*zbuf;
	char				dir;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*spr;
	char				**grid;
}				t_map;

typedef struct	s_cub3d
{
	t_map			*map;
	t_img			img_one;
	t_img			img_two;
	t_img			*curr_frame;
	t_ray			ray;
	t_move			move;
	t_texture		text;
	t_spr			spr;
	int				fd;
	void			*mlx;
	void			*win;
	long			frame;
}				t_cub3d;

void			ft_make_screenshot(t_cub3d *cub);
void			ft_bitmap_data(t_cub3d *cub);
void			ft_bitshifting(int num, unsigned char *dest);
void			ft_bitmap_file(t_cub3d *cub);

void			ft_is_screenshot(char *arg, t_map *info);
void			ft_start_cub3d(t_cub3d *cub, t_map *info);
void			ft_argcheck(int argc, char *mapfile, t_map *info);
int				ft_update_mlx(t_cub3d *cub);

int				ft_error(int error);

void			ft_floodfill(t_map *copy, int x, int y);
int				ft_check_valid_map(t_map *copy, int x, int y);

void			ft_handle_map(t_map *info, char *cub);
void			ft_get_grid(t_map *info, char *cub);
void			ft_get_dir_pos(t_map *info);
void			ft_set_dir_pos(t_map *info, int i, int j);
void			ft_copy_grid(t_map *info, t_map *copy);

void			ft_count_sprites(t_cub3d *cub);
void			ft_get_sprites(t_cub3d *cub, int index);
void			ft_get_spr_array(t_sprite **sprite, t_sprite spr,
									int index, int count);
void			ft_set_spr_array(t_sprite **sprite, t_sprite spr,
									int k, int nmbr);
void			ft_set_spr_dims(t_cub3d *cub, int index);

void			ft_get_spr_vals(t_cub3d *cub);
void			ft_set_spr_vals(t_cub3d *cub, double ratio, double size);
void			ft_load_sprite(t_cub3d *cub);
void			ft_load_spr_helper(t_cub3d *cub, int y);
int				ft_get_sprite_color(t_cub3d *cub, int width, int height);

t_cub3d			ft_start_window(t_map *info);
void			ft_get_screen_size(t_map *info, void *mlx);
void			ft_get_img_adr(t_map *info, t_img *img_one,
								t_img *img_two, void *mlx);
void			ft_put_pixel_img(t_img *img, int x, int y, int color);
int				ft_render_window(t_cub3d *cub);

void			ft_init_ray(t_ray *ray, t_map *info);
void			ft_get_text_img(t_cub3d *cub);
void			ft_get_text_adr(t_cub3d *cub);
void			ft_init_dirs(t_ray *ray, t_map *info);
void			ft_init_planes(double fov, t_ray *ray);

t_map			ft_set_map_struct(t_map *info);
void			ft_set_move_struct(t_cub3d *cub);

int				ft_hooks(t_cub3d *cub);
int				ft_keypress(int key, t_cub3d *cub);
int				ft_keyrelease(int key, t_cub3d *cub);
int				ft_exit(void);

void			ft_set_move_vals_one(t_cub3d *cub);
void			ft_set_move_vals_two(t_cub3d *cub);
void			ft_check_wall_spr_coll(t_cub3d *cub);
void			ft_set_rot_vals(t_cub3d *cub);

int				ft_gnl_cub3d(t_map *info, char **line);
int				ft_read_line(char *buff, int fd, int *rd);
int				ft_make_line(char **line, char *buff, int *index, int *rd);
void			ft_remainder(char *buff, int j);
void			ft_check_end_line(t_map *info, char c);

void			ft_parse_map(t_map *info);
void			ft_set_map_vals(t_map *info);
int				ft_check_elems(t_map *info, char flag);
char			ft_get_elems(char *line, int *i);
void			ft_handle_elems(t_map *info, char element, char *line, int *i);

void			ft_get_path(t_map *info, char element, char *line, int *i);
void			ft_get_texture(t_map *info, char element, char *path);
void			ft_get_color(t_map *info, char element, char *line, int *i);
void			ft_set_rbg(t_map *info, char element);
void			ft_get_resolution(t_map *info, char *line, int *i);

void			ft_set_delta(t_cub3d *cub);
void			ft_cast_ray(t_cub3d *cub);
void			ft_step_dir(t_cub3d *cub);
void			ft_set_step_dir(t_cub3d *cub);
void			ft_find_wall_hit(t_cub3d *cub);

void			ft_set_wall_values(t_cub3d *cub, int x, int so_ea);
int				ft_get_wall_values(t_cub3d *cub, int x);
void			ft_render_wall(t_cub3d *cub, int start, int end, int x);
int				ft_get_text_color(t_cub3d *cub, int start, int end, double y);
double			ft_set_text_color(t_cub3d *cub, double x);

void			ft_skipspace(char *line, int *i);

#endif
