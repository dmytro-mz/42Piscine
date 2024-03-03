#ifndef FUNC_DEF_H
# define FUNC_DEF_H

char	*ft_strndup(char *str, int len);
void	free_dict(char ***dict);
int		get_key_len(char *buffer);
int		get_value_len(char *buffer);
char	***parse_dict(char *dict_path);
int		parse_line(char ***dict, char *buffer, int start);
char	*normalize_num(char *num);
void	write_dict_error(void);
void	write_error(void);
void	write_new_line(void);
void	write_num(char *num, char ***dict, int is_first);
void	write_string(char *str);
char	*str_cpy(char *str);
int		str_len(char *str);
int		validate_key(char *buffer, int *index);
int		validate_line(char *buffer, int start);

#endif