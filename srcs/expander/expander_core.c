/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:37 by becastro          #+#    #+#             */
/*   Updated: 2022/10/05 18:36:12 by umartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"
#include "lexer.h"

char	*expander_core(char **cmds, char **env)
{
	int		i;
	char	*aux1;
	char	*aux2;

	i = 0;
	aux1 = NULL;
	aux2 = NULL;
	while (i <= (ft_doublestrlen(cmds) - 1))
	{
		if (!aux1)
			aux1 = expander_main(cmds[i], env);
		else if (aux1)
		{
			aux2 = expander_main(cmds[i], env);
			aux1 = ft_strjoin(aux1, aux2);
		}
		i++;
	}
	return (aux1);
}

char	*expand_trimmer(char	*str)
{
	int		i;
	int		c;
	char	*rtn;

	i = 0;
	c = 0;
	rtn = ft_calloc(sizeof(char *), (ft_strlen(str) - 1));
	while (++i < (ft_strlen(str) - 1))
	{
		rtn[c] = str[i];
		c++;
	}
	rtn[i] = 0;
	return (rtn);
}

char	*expand_first_trimmer(char	*str)
{
	int		i;
	int		c;
	char	*rtn;

	i = 0;
	c = 0;
	rtn = ft_calloc(sizeof(char *), (ft_strlen(str) - 2));
	while (++i < (ft_strlen(str)))
	{
		rtn[c] = str[i];
		c++;
	}
	rtn[i] = 0;
	return (rtn);
}

char	*expander_main(char	*str, char **env)
{
	char	**rtn;
	char	*r;
	int		i;
	int		c;

	rtn = NULL;
	i = -1;
	if (str[0] == SINGLE_QUOTE)
		return (expand_trimmer(str));
	else if (str[0] == DOUBLE_QUOTE)
		rtn = expander(expand_trimmer(str), env);
	else
		rtn = expander(str, env);
	r = double_joiner(rtn);
	return (r);
}

char	*double_joiner(char **temp)
{
	int		i;
	char	*aux;
	char	*rtn;

	i = 1;
	rtn = ft_strdup(temp[0]);
	while (temp[i])
	{
		aux = ft_strdup(temp[i]);
		rtn = ft_strjoin(rtn, aux);
		i++;
	}
	return (rtn);
}

char	**expander(char	*str, char **env)
{
	int		i;
	int		n;
	int		a;
	char	**temp;
	char	*aux;

	temp = malloc(sizeof(char *) * (expand_arg_num(str)) + 1);
	temp = expand_splitter(str, temp);
	i = -1;
	i = -1;
	n = 0;
	while (temp[++i])
	{
		if ((temp[i][0] == 36) && (ft_strlen(temp[i]) > 1))
		{
			aux = env_replacer(temp[i], env);
			temp[i] = ft_strdup(aux);
		}
	}
	return (temp);
}

char	*env_replacer(char *str, char **env)
{
	int		i;
	int		n;
	int		r;
	char	*val;
	char	*p;

	i = -1;
	str = expand_first_trimmer(str);
	p = ft_itoa((int)getpid());
	if (str[0] == 36)
		return (p);
	while (env[++i])
	{
		if ((!ft_strncmp(str, env[i], (num_until_equal(env[i]))))
			&& (ft_strlen(str) == num_until_equal(env[i])))
		{
			val = ft_calloc(sizeof(char *),
					(ft_strlen(env[i]) - ft_strlen(str)));
			n = (ft_strlen(str));
			r = 0;
			while (env[i][++n])
				val[r++] = env[i][n];
			val[r] = 0;
			return (val);
		}
	}
	val = "";
	return (val);
}

int	num_until_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 61)
			return (i);
		i++;
	}
	return (0);
}

int	expand_arg_num(char *str)
{
	int		e;
	int		c;

	e = 0;
	c = 0;
	while (str[e])
	{
		if (str[e] == 36)
		{
			if (str[e + 1] == 36)
			{
				c++;
				e += 2;
				continue ;
			}
			c++;
			e++;
			while ((str[e]) && ((str[e] != '$') && (str[e] != 32)))
				e++;
			e--;
		}
		else
		{
			c++;
			while ((str[e]) && ((str[e] != '$')))
				e++;
		}
		e++;
	}
	return (c);
}

char	**expand_splitter(char *str, char **rtn)
{
	int		e;
	int		n;
	int		l;
	int		a;
	char	*aux;

	e = 0;
	n = 0;
	while (str[e])
	{
		if (str[e] == 36)
		{
			l = e;
			if (str[e + 1] == 36)
				e ++;
			else
			{
				e++;
				while ((str[e]) && ((str[e] != '$') && (str[e] != 32)))
					e++;
				e--;
			}
			aux = ft_calloc(sizeof(char *), (e - l) + 1);
			a = 0;
			while (l <= e)
				aux[a++] = str[l++];
			aux[l] = 0;
			rtn[n] = ft_strdup(aux);
			free(aux);
			n++;
		}
		else
		{
			l = e;
			while ((str[e]) && ((str[e] != '$')))
				e++;
			e--;
			aux = ft_calloc(sizeof(char *), (e - l) + 1);
			a = 0;
			while (l <= e)
				aux[a++] = str[l++];
			aux[l] = 0;
			rtn[n] = ft_strdup(aux);
			free(aux);
			n++;
		}
		e++;
	}
	rtn[n] = NULL;
	return (rtn);
}
