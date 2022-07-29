#include "shell.h"

/**
 * add_rvar_node - adds a variable at the end of a r_var list.
 * @head: head of the linked list.
 * @ln_var: length of the variable
 * @val: value of the variable.
 * @ln_val: length of the value
 * Return: address of the head.
 */
r_var *add_rvar_node(r_var **head, int ln_var, char *val, int ln_val)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = ln_var;
	new->val = val;
	new->len_val = ln_val;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list
 * Return: no return
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
