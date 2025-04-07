so_long is the first game I've built. It's a project that allowed me to use and understand graphical assets and animations. The main part of the program communicates with the MLX and X11.

Functions that I've used:

mlx_init: Initialises the MLX library. Must be called before using any other functions.

mlx_new_window: Creates a new window instance.

mlx_hook: Registers events.

mlx_loop: Loops over the MLX pointer, triggeering each hook in order of registration.

mlx_xpm_file_to_image: Converts an XPM file to an MLX image pointer.

mlx_put_image_to_window: Puts ytour image to the screen at the given coordinates.

mlx_destroy_image: Frees the image.

mlx_destroy_window: Frees the window instance.

mlx_destroy_display: Frees MLX.

