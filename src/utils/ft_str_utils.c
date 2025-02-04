#include "../../include/utils.h"

void	ft_strstr_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

int	ft_strstr_len(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_strnstrstr(char **str, char *locate)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (str && str[i])
	{
		if (ft_strncmp(str[i], locate, ft_strlen(locate)) == 0)
			total++;
		i++;
	}
	return (total);
}

char	**ft_strstr_dup(char **str)
{
	char	**dup;
	size_t	i;

	i = 0;
	dup = NULL;
	if (str == NULL)
		return (NULL);
	dup = (char **)ft_calloc(sizeof(char *), (size_t)ft_strstr_len(str) + 1);
	if (dup == NULL)
		return (NULL);
	while (i < (size_t)ft_strstr_len(str))
	{
		dup[i] = ft_strdup(str[i]);
		if (dup[i] == NULL)
		{
			ft_strstr_free(dup);
			return (NULL);
		}
		i++;
	}
	return (dup);
}

char	**ft_strstr_join(char **str, char **str1)
{
	char	**string;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
	{
		string = ft_calloc(sizeof(char *), (size_t)ft_strstr_len(str1) + 1);
		while (i != ft_strstr_len(str1) && str[i] != NULL)
			string[j++] = ft_strdup(str1[i++]);
		return (string);
	}
	size = ft_strstr_len(str) + ft_strstr_len(str1);
	string = ft_calloc(sizeof(char *), (size_t)size + 1);
	if (string == NULL)
		return (NULL);
	while (i != ft_strstr_len(str) && str[i] != NULL)
		string[j++] = ft_strdup(str[i++]);
	i = 0;
	while (i != ft_strstr_len(str1) && str1[i] != NULL)
		string[j++] = ft_strdup(str1[i++]);
	string[j] = NULL;
	return (string);
}
