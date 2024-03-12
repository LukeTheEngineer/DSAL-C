/**
 * @file    DSAL-C.c
 * @brief   BSD 3-Clause License
 * @date    March 12th, 2024
 *
 * @copyright (c) 2024 Lukas R. Jackson
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/DSAL-C.h"

// Function to create a new node and append it to the end of the list
struct node* append(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to append a node to the beginning of the list
void append_beginning(struct node** head, int data) {
    struct node* new_node = append(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to append a node to the end of the list
void append_end(struct node** head, int data) {
    struct node* new_node = append(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the list
void print_list(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to remove a node from the list by index
void remove_node(struct node** head, const int index) {
    if (*head == NULL) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    if (index == 0) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node* current = *head;
    int i = 0;
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    if (current == NULL || current->next == NULL) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    struct node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to delete the entire list
void del_list(struct node** head) {
    struct node* current = *head;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
