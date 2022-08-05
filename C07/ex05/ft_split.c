#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index])
			return (1);
		index++;
	}
	return (0);
}

char	**ft_count_word(char *str, char *charset)
{
	int		index;
	int		words;
	char	**out;

	words = 0;
	index = 0;
	while (str[index])
	{
		if (!ft_is_charset(str[index], charset))
		{
			words += 1;
			while (str[index] && !ft_is_charset(str[index], charset))
				index++;
		}
		index++;
	}
	out = (char **)malloc((words + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	out[words] = NULL;
	return (out);
}

int	ft_allocate_word(char *str, char **dest, char *charset)
{
	int	wd_len;

	wd_len = 0;
	while (str[wd_len] && !ft_is_charset(str[wd_len], charset))
		wd_len++;
	*dest = (char *)malloc((wd_len + 1) * sizeof(char));
	if (!*dest)
		return (0);
	wd_len = 0;
	while (str[wd_len] && !ft_is_charset(str[wd_len], charset))
	{
		(*dest)[wd_len] = str[wd_len];
		wd_len++;
	}
	return (wd_len);
}

int	ft_fill(char *str, char *charset, char **out)
{
	int		word;
	int		index;

	index = -1;
	word = 0;
	while (str[++index])
	{
		if (!ft_is_charset(str[index], charset))
		{
			index += ft_allocate_word(&str[index], &out[word], charset);
			word += 1;
		}
	}
	return (word);
}

char	**ft_split(char	*str, char *charset)
{
	char	**out;

	out = ft_count_word(str, charset);
	if (!out)
		return (NULL);
	ft_fill(str, charset, out);
	return (out);
}
