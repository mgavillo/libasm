#include <libasm.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

void	delete_list(t_list **list)
{
		t_list *current;
		t_list *next;
 
		current = *list;
    	while (current != NULL)
    	{
        	next = current->next;
        	free(current);
        	current = next;
    	}
		*list = NULL;
}

void	list_add_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst || !new)
		return ;
	if (*alst)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}

t_list	*list_new(void *data)
{
	t_list		*lst;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("%p\n", tmp->data);
		tmp = tmp->next;
	}
}

void	print_string_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}

int get_int(void* value){
	int i;

	i = *((int *) value);
    return (i);
}

int cmp_int(void *a, void *b)
{
	//printf("a = %d\n", get_int(a));
	//printf("b = %d\n", get_int(b));
	return (get_int(a) - get_int(b));
}

void    atoi_base_test(char *nb, char* base, int expected)
{
	int ret;

	ret = ft_atoi_base(nb, base);
	if (ret == expected)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
        
}

void 	list_push_front_test()
{
	t_list	*list;

	list = NULL;
	ft_list_push_front(&list, strdup("coucou"));
	if (cmp_int(list->data, "coucou") == 0)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	ft_list_push_front(&list, "6");
	if (cmp_int(list->data, "6") == 0)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	delete_list(&list);
}

void 	list_remove_if_test()
{
	t_list	*list;


	list = NULL;
	ft_list_remove_if(&list, "cc", strcmp);
	list_add_back(&list, list_new("cc"));
	ft_list_remove_if(&list, "cc", strcmp);
	if (list == NULL)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	list_add_back(&list, list_new("cc"));
	list_add_back(&list, list_new("coucou"));
	ft_list_remove_if(&list, "cc", strcmp);
	if (strcmp(list->data, "coucou") == 0)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	delete_list(&list);
}

void	list_sort_test()
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;

	list_add_back(&list, list_new(strdup("2")));
	list_add_back(&list, list_new(strdup("8")));
	list_add_back(&list, list_new(strdup("5")));
	list_add_back(&list, list_new(strdup("coucou")));
	list_add_back(&list, list_new(strdup("9")));
	list_add_back(&list, list_new(strdup("blabla")));
	list_add_back(&list, list_new(strdup("lol")));

	tmp = list;
	//print_string_list(list);
	ft_list_sort(&list, strcmp);
	//print_string_list(list);
	while(tmp->next)
	{
		if (strcmp(tmp->data, tmp->next->data) <= 0)
			printf("" GREEN "[OK] " RESET "");
		else
			printf("" RED "[KO] " RESET "");
		tmp = tmp->next;
	}
	delete_list(&list);
}

void	list_size_test(int len)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = len;
	while (i > 0)
	{
		list_add_back(&list, list_new((void *)(uintptr_t)len));
		i--;
	}
	len = len < 0 ? 0 : len; 
	if (len == ft_list_size(list))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	delete_list(&list);
}


void	strmcp_test(char *str1, char * str2)
{
	int ret;
	int ref;

	ref = strcmp(str1, str2);
	ret = ft_strcmp(str1, str2);
	if ((ret < 0 && ref < 0) || (ret > 0 && ref > 0) || (ret == 0 && ref == 0))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
}

void	strcpy_test(char *ref)
{
	char a[500];

	bzero(a, 500);
	ft_strcpy(a, ref);
	if (strcmp(a, ref) == 0)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	
}

void	strdup_test(char *str)
{
    char	*str1;
	char	*str2;

	str1 = ft_strdup(str);
	str2 = strdup(str);
	if (!ft_strcmp(str1, str2))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	if(str1)
		free(str1);
	if(str2)
		free(str2);
}

void	strlen_test(char * str)
{
	int ret;
	int ref;
	ref = strlen(str);
	ret = ft_strlen(str);
	if (ret == ref)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
}

void	WriteRead_test(char *str)
{
	char buf1[100];
	char buf2[100];
	int	fd;
	int ret;
	int len;

	bzero(buf1, '0');
	bzero(buf2, '0');
	len = ft_strlen(str);
	fd = open("./test.txt", O_WRONLY);
	ret = ft_write(fd, str, len);
	printf("errno : %d\n", errno);
	printf("ft_write ret = %d\n", ret);
	ret = write(fd, str, len);
	printf("errno : %d\n", errno);
	printf("write ret = %d\n", ret);
	close(fd);

	fd = open("test.txt", O_RDONLY);
	ft_read(fd, buf1, len);
	printf("ft_read = %s\n", buf1);
	read(fd, buf2, len);
	printf("read = %s\n", buf2);
	close(fd);
	if (!strcmp(buf1, buf2))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
}

int main(void)
{
	printf("___________________________\n");
	printf("..........atoi_base........\n");
	printf("___________________________\n");

	atoi_base_test("-3", "0123456789", -3);
	atoi_base_test("", "0123456789", 0);
	atoi_base_test("-2147483648", "0123456789", -2147483648);
	atoi_base_test("2147483647", "0123456789", 2147483647);
	atoi_base_test("2147483k648", "0123456789", 2147483);

	printf("\n\n___________________________\n");
	printf(".........push_front........\n");
	printf("___________________________\n");

	list_push_front_test();

	printf("\n\n___________________________\n");
	printf("..........remove_if........\n");
	printf("___________________________\n");

	list_remove_if_test();

	printf("\n\n___________________________\n");
	printf("............sort...........\n");
	printf("___________________________\n");

	list_sort_test();

	//tester avec max int, 
	printf("\n\n___________________________\n");
	printf("..........list_size........\n");
	printf("___________________________\n");
	list_size_test(0);
	list_size_test(-8);
	list_size_test(1);
	list_size_test(66);


	//changer int en -1, 0, 1 
	printf("\n\n___________________________\n");
	printf("............strcmp.........\n");
	printf("___________________________\n");
    strmcp_test("cc", "");
    strmcp_test("non", "papa");
    strmcp_test("blabalabla&", "blabalabla&");


	printf("\n\n___________________________\n");
	printf("............strcpy.........\n");
	printf("___________________________\n");
    strcpy_test("barbapapa");
	strcpy_test("");
    strcpy_test("\0\0");
    strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");
	
	printf("\n\n___________________________\n");
	printf("............strlen.........\n");
	printf("___________________________\n");
    strlen_test("coucou");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");
    strlen_test("");
	

	printf("\n\n___________________________\n");
	printf("...........strdup..........\n");
	printf("___________________________\n");
	strdup_test("Que neni");
	strdup_test("666666666666666666666666666666666666666666666666666666666666666666");
	strdup_test("");
	strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");

	printf("\n\n___________________________\n");
	printf(".......write/read..........\n");
	printf("___________________________\n");
	WriteRead_test(NULL);
	WriteRead_test("Lorm ipsum");
    return(0);
}
