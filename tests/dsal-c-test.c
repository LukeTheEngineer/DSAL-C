/**
 * @file    dsal-c-test.c
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

#include "../include/DSAL-C.h"
#include <stdio.h>

int main() {
    // Create an empty list
    struct node* head = NULL;

    // Test append_beginning() function
    printf("Appending elements to the beginning of the list: ");
    append_beginning(&head, 5);
    append_beginning(&head, 10);
    append_beginning(&head, 15);
    print_list(head); // Expected output: 15 10 5

    // Test append_end() function
    printf("Appending elements to the end of the list: ");
    append_end(&head, 20);
    append_end(&head, 25);
    append_end(&head, 30);
    print_list(head); // Expected output: 15 10 5 20 25 30

    // Test remove_node() function
    printf("Removing element at index 2: ");
    remove_node(&head, 2);
    print_list(head); // Expected output: 15 10 20 25 30

    // Test del_list() function
    printf("Deleting the list: ");
    del_list(&head);
    print_list(head); // Expected output: (empty list)

    return 0;
}