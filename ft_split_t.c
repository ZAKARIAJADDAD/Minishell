
#include "minishell.h"
#include "LIBFT/libft.h"

static int	free_space(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	return (1);
}

static	char	**aloc(char const *s, char sep)
{
	char	**k;
(void)sep;
(void)s;
	k = (char **)ft_calloc((2), sizeof(char *));
	if (!k)
		return (NULL);
	return (k);
}

static int	ww(char const *s, char sep, int i)
{
	(void)sep;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

char	**ft_split_t(char const *s, char sep)
{
	char	**p;
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	p = aloc(s, sep);
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (s[i] != sep)
		{
			start = i;
			i = ww(s, sep, i);
			p[j++] = ft_substr(s, start, (i - start));
			(!p) && (free_space(p));
		}
		else
			i++;
	}
	return (p);
}