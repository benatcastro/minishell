/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umartin- <umartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:37 by becastro          #+#    #+#             */
/*   Updated: 2022/09/30 14:06:38 by umartin-         ###   ########.fr       */
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

char	*expander_main(char	*str, char **env)
{
	char	*rtn;
	int		i;
	int		c;

	rtn = NULL;
	i = -1;
	if (str[0] == SINGLE_QUOTE)
		rtn = ft_strtrim(str, "'");
	else if (str[0] == DOUBLE_QUOTE)
	{
		rtn = ft_strtrim(str, "\"");
		while (rtn[++i])
		{
			if ((rtn[i]) && (rtn[i] == 36))
				rtn = expander(rtn, env);
		}
	}
	else
	{
		while (str[++i])
		{
			if (str[i] == 36)
			{
				rtn = expander(str, env);
				break ;
			}
			rtn = str;
		}
	}
	return (rtn);
}

char	*expander(char	*str, char **env)
{
	char	**rtn;
	char	*aux;
	char	*aux2;
	int		a;
	int		i;

	i = -1;
	rtn = expand_splitter(str);
	while (rtn[++i])
	{
		a = 0;
		if (rtn[i][0] == 36)
		{
			aux = ft_calloc(sizeof(char *), ft_strlen(rtn[i]));
			while (rtn[i][++a])
				aux[a - 1] = rtn[i][a];
			aux[a - 1] = 0;
			aux = env_replacer(aux, env);
			if (!aux2)
				aux2 = ft_strdup(aux);
			else if ((!aux2) && (aux2))
				aux2 = ft_strjoin(aux2, aux);
			free(aux);
		}
		else
		{
			aux = ft_calloc(sizeof(char *), ft_strlen(rtn[i]));
			while (rtn[i][a++])
				aux[a - 1] = rtn[i][a];
			if (!aux2)
				aux2 = ft_strdup(aux);
			else if ((!aux2) && (aux2))
				aux2 = ft_strjoin(aux2, aux);
			free(aux);
		}
	}
	return (aux2);
}

char	*env_replacer(char *str, char **env)
{
	int		i;
	int		n;
	int		r;
	char	*val;

	i = 0;
	while (env[++i])
	{
		if (ft_strncmp(str, env[i], ft_strlen(str)))
		{
			val = ft_calloc(sizeof(char *),
					(ft_strlen(env[i]) - ft_strlen(str)));
			n = (ft_strlen(str) + 1);
			r = 0;
			while (env[i][++n])
				val[r++] = env[i][n];
			val[r] = 0;
			return (val);
		}
	}
	val = NULL;
	return (val);
}

char	**expand_splitter(char *str)
{
	int		i;
	int		n;
	char	**temp;

	temp = malloc(sizeof(char *) * (expand_arg_num(str)) + 1);
	temp[(expand_arg_num(str))] = NULL;
	i = -1;
	n = 0;
	while (++i <= ((int)ft_strlen(str) - 1))
	{
		if (str[i] == 36)
			exander_dollar_find(str, temp, &i, &n);
		else
			expaner_no_dollar(str, temp, &i, &n);
	}
	return (temp);
}
