#include "stdio.h"
#include "stdint.h"

typedef union 
{
    uint16_t frame;
    
    struct 
    {        
        unsigned int application_process_idenfier : 11;
        unsigned int second_header_flag : 1;
        unsigned int packet_type : 1;
        unsigned int packet_version_number : 3;
                
    }primary_header_t;

    struct 
    {
        unsigned int packet_sequence_count_or_name : 14;
        unsigned int sequence_flag : 2;     
    
    }packet_sequence_control_t;

    struct 
    {
       uint16_t data_length;

    }packet_len_t;
     
}u_primary_header_frame;

uint8_t primary_header_buf_fr1[6] = {0x10 , 0x20, 0xC0, 0x00, 0x00, 0x10};
uint8_t primary_header_buf_fr2[6] = {0x00 , 0x20, 0xC0, 0x01, 0x00, 0x10};

int main(int argc, char* argv[])
{

    /* First Frame */
    {
        u_primary_header_frame* fr_ver_pid = (u_primary_header_frame *)&primary_header_buf_fr1[0];
        u_primary_header_frame* fr_p_seq = (u_primary_header_frame *)&primary_header_buf_fr1[2];
        u_primary_header_frame* fr_len = (u_primary_header_frame *)&primary_header_buf_fr1[4];

        fr_ver_pid -> frame = (fr_ver_pid -> frame >> 8) | (fr_ver_pid -> frame << 8);
        printf("packet_version_number : %i \n", fr_ver_pid -> primary_header_t.packet_version_number);
        printf("packet_type : %i \n", fr_ver_pid -> primary_header_t.packet_type);
        printf("second_header_flag : %i \n", fr_ver_pid -> primary_header_t.second_header_flag);
        printf("application_process_idenfier : %i \n", fr_ver_pid -> primary_header_t.application_process_idenfier);

        fr_p_seq -> frame = (fr_p_seq -> frame >> 8) | (fr_p_seq -> frame << 8);
        printf("sequence_flag : %i \n", fr_p_seq -> packet_sequence_control_t.sequence_flag);
        printf("packet_sequence_count_or_name: %i \n", fr_p_seq -> packet_sequence_control_t.packet_sequence_count_or_name);

        fr_len -> frame = (fr_len -> frame >> 8) | (fr_len -> frame << 8);

        printf("sequence_flag : %i \n", fr_len -> packet_len_t.data_length);
    }

        printf("\r\n\r\n");

    /* Second Frame */
    {
        u_primary_header_frame* fr_ver_pid = (u_primary_header_frame *)&primary_header_buf_fr2[0];
        u_primary_header_frame* fr_p_seq = (u_primary_header_frame *)&primary_header_buf_fr2[2];
        u_primary_header_frame* fr_len = (u_primary_header_frame *)&primary_header_buf_fr2[4];

        fr_ver_pid -> frame = (fr_ver_pid -> frame >> 8) | (fr_ver_pid -> frame << 8);
        printf("packet_version_number : %i \n", fr_ver_pid -> primary_header_t.packet_version_number);
        printf("packet_type : %i \n", fr_ver_pid -> primary_header_t.packet_type);
        printf("second_header_flag : %i \n", fr_ver_pid -> primary_header_t.second_header_flag);
        printf("application_process_idenfier : %i \n", fr_ver_pid -> primary_header_t.application_process_idenfier);

        fr_p_seq -> frame = (fr_p_seq -> frame >> 8) | (fr_p_seq -> frame << 8);
        printf("sequence_flag : %i \n", fr_p_seq -> packet_sequence_control_t.sequence_flag);
        printf("packet_sequence_count_or_name: %i \n", fr_p_seq -> packet_sequence_control_t.packet_sequence_count_or_name);

        fr_len -> frame = (fr_len -> frame >> 8) | (fr_len -> frame << 8);

        printf("sequence_flag : %i \n", fr_len -> packet_len_t.data_length);
    }
}