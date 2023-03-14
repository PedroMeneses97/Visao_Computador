
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "vc.h"

// Gerar negativo da imagem Gray
int vc_gray_negative(IVC *srcdst)
{
    unsigned char *data = (unsigned char *)srcdst->data;
    int width = srcdst->width;
    int height = srcdst->height;
    int bytesperline = srcdst->width * srcdst->channels;
    int channels = srcdst->channels;
    int x, y;
    long int pos;

    // Verificação de erros
    if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;

    // Validação para garantir que o channel é 1
    if (channels != 1) return 0;

    // Inverte a imagem Gray
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            pos = y * bytesperline + x * channels;
            data[pos] = 255 - data[pos];
        }
    }

    return 1;
}


// Gerar negativo da imagem RGB
int vc_rgb_negative(IVC *srcdst){
    unsigned char *data = (unsigned char *)srcdst->data;
    int width = srcdst->width;
    int height = srcdst->height;
    int bytesperline = srcdst->width * srcdst->channels;
    int channels = srcdst->channels;
    int x, y;
    long int pos;


    // Verificação de erros
    if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;

    // Validar que os channels são diferente de 3.
    if (channels != 3) return 0;


    // Inverte a imagem RGB
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){

            pos = y * bytesperline + x * channels;
            data[pos] = 255 - data[pos];
            data[pos + 1] = 255 - data[pos + 1];
            data[pos + 2] = 255 - data[pos + 2];
        }
    }
    
    return 1;
}





// Troca RGB - Vermelho para gray
int vc_rgb_get_red_gray(IVC *srcdst){

    unsigned char *data = (unsigned char *)srcdst->data;
    int width = srcdst->width;
    int height = srcdst->height;
    int bytesperline = srcdst->width * srcdst->channels;
    int channels = srcdst->channels;
    int x, y;
    long int pos;

    // Verificação de erros
    if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;

    // Validar que os channels são diferente de 3.
    if (channels != 3) return 0;

        // Inverte a imagem RGB
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){

            pos = y * bytesperline + x * channels;

            data[pos + 1] = data[pos]; // BLUE
            data[pos + 2] = data[pos]; // GREEN
        }
    }
    
    return 1;
}

int vc_rgb_get_red(IVC *srcdst){

    unsigned char *data = (unsigned char *)srcdst->data;
    int width = srcdst->width;
    int height = srcdst->height;
    int bytesperline = srcdst->width * srcdst->channels;
    int channels = srcdst->channels;
    int x, y;
    long int pos;

    // Verificação de erros
    if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;

    // Validar que os channels são diferente de 3.
    if (channels != 3) return 0;

        // Inverte a imagem RGB
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){

            pos = y * bytesperline + x * channels;
            data[pos ] = data[pos]; // BLUE
            data[pos + 1] = 0; // BLUE
            data[pos + 2] = 0; // GREEN
        }
    }
    
    return 1;
}


int vc_rgb_get_green_gray(IVC *srcdst){

    unsigned char *data = (unsigned char *)srcdst->data;
    int width = srcdst->width;
    int height = srcdst->height;
    int bytesperline = srcdst->width * srcdst->channels;
    int channels = srcdst->channels;
    int x, y;
    long int pos;

    // Verificação de erros
    if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;

    // Validar que os channels são diferente de 3.
    if (channels != 3) return 0;

        // Inverte a imagem RGB
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){

            pos = y * bytesperline + x * channels;
            
            data[pos] = data[pos + 1]; // RED
            data[pos + 2] = data[pos +1]; // BLUE

            
        }
    }
    
    return 1;

}

int vc_rgb_get_green(IVC *srcdst){

    unsigned char *data = (unsigned char *)srcdst->data;
    int width = srcdst->width;
    int height = srcdst->height;
    int bytesperline = srcdst->width * srcdst->channels;
    int channels = srcdst->channels;
    int x, y;
    long int pos;

    // Verificação de erros
    if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;

    // Validar que os channels são diferente de 3.
    if (channels != 3) return 0;

        // Inverte a imagem RGB
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){

            pos = y * bytesperline + x * channels;
            data[pos] = 0; // r
            data[pos + 1] = data[pos +1]; // g
            data[pos + 2] = 0; // b
        }
    }
    
    return 1;
}



// Troca RGB - Blue para gray
int vc_rgb_get_blue_gray(IVC *srcdst){

    unsigned char *data = (unsigned char *)srcdst->data;
    int width = srcdst->width;
    int height = srcdst->height;
    int bytesperline = srcdst->width * srcdst->channels;
    int channels = srcdst->channels;
    int x, y;
    long int pos;

    // Verificação de erros
    if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;

    // Validar que os channels são diferente de 3.
    if (channels != 3) return 0;

        // Inverte a imagem RGB
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){

            pos = y * bytesperline + x * channels;

            data[pos] = data[pos + 2]; // RED
            data[pos + 1] = data[pos + 2]; // GREEN
            
            
        }
    }
    
    return 1;

}

int vc_rgb_get_blue(IVC *srcdst){

    unsigned char *data = (unsigned char *)srcdst->data;
    int width = srcdst->width;
    int height = srcdst->height;
    int bytesperline = srcdst->width * srcdst->channels;
    int channels = srcdst->channels;
    int x, y;
    long int pos;

    // Verificação de erros
    if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;

    // Validar que os channels são diferente de 3.
    if (channels != 3) return 0;

        // Inverte a imagem RGB
    for (y = 0; y < height; y++){
        for (x = 0; x < width; x++){

            pos = y * bytesperline + x * channels;
            data[pos] = 0; // R
            data[pos + 1] = 0; // G
            data[pos + 2] = data[pos + 2]; // B
        }
    }
    
    return 1;
}




int vc_rgb_to_gray(IVC *src, IVC *dst){

    // Info da Source Image (src)
    unsigned char *datasrc = (unsigned char *) src->data;
    int bytesperline_src = src->width * src->channels;
    int channels_src = src->channels;

    // Info da Imagem Destino (dst)
    unsigned char *datadst = (unsigned char *) dst->data;
    int bytesperline_dst = dst->width * dst->channels;
    int channels_dst = dst->channels;

    // Width e Height da imagem Src
    int width = src->width; 
    int height = src->height;

    // Aux Variable
    int x, y;
    long int pos_src, pos_dst; 
    float rf, gf, bf;

    // Verificação de erros
    if((src->width <= 0) || (src->height <= 0) || (src->data == NULL)) return 0; 
    if((src->width != dst->width) || (src->height != dst->height)) return 0;
    if((src->channels != 3) || (dst->channels != 1)) return 0;
    
    for (y = 0; y < height; y++){

        for (x = 0; x < width; x++){
            
            pos_src = y * bytesperline_src + x * channels_src; // Posição src
            pos_dst = y * bytesperline_dst + x * channels_dst; // Posição dst

            rf = (float) datasrc[pos_src]; // red
            gf = (float) datasrc[pos_src + 1]; // green
            bf = (float) datasrc [pos_src + 2]; // blue

            datadst [pos_dst] = (unsigned char) ((rf * 0.299) + (gf * 0.587) + (bf * 0.114));
        }

    }

    return 1;
}





int vc_rgb_to_hsv(IVC *src, IVC *dst){

    // Info da Source Image (src)
    unsigned char *datasrc = (unsigned char *) src->data;
    int bytesperline_src = src->width * src->channels;
    int channels_src = src->channels;

    // Info da Imagem Destino (dst)
    unsigned char *datadst = (unsigned char *) dst->data;
    int bytesperline_dst = dst->width * dst->channels;
    int channels_dst = dst->channels;

    // Width e Height da imagem Src
    int width = src->width; 
    int height = src->height;

    // Aux Variable
    int x, y;
    long int pos_src, pos_dst; 
    float red, green, blue;

    // Hsv floats
    float hue,saturation,value;
    float max,min;

    // Verificação de erros
    if((src->width <= 0) || (src->height <= 0) || (src->data == NULL)) return 0; 
    if((src->width != dst->width) || (src->height != dst->height)) return 0;
    if((src->channels != 3) || (dst->channels != 3)) return 0;
    
    for (y = 0; y < height; y++){

        for (x = 0; x < width; x++){
            
            pos_src = y * bytesperline_src + x * channels_src; // Posição src
            pos_dst = y * bytesperline_dst + x * channels_dst; // Posição dst

            
            red = (float) datasrc[pos_src]; // red
            green = (float) datasrc[pos_src + 1]; // green
            blue = (float) datasrc [pos_src + 2]; // blue
            

            // Cálcular Máximo e Mínimo
            max = (red >= green && red >= blue) ? red : (green >= red && green >= blue) ? green : blue;
            min = (red <= green && red <= blue) ? red : (green <= red && green <= blue) ? green : blue;

            // Declarar os valores para o HSV
            value = max;
            saturation = (max - min) / value;

            // Calcular o Hue
            if( (max == red) && (green >= blue) ){
                hue = 60 * (green - blue) / (max - min);
            }
            else if( (max == red) && (blue >= green) ){
                hue = 360 + 60 * (green - blue) / (max - min);
            }
            else if ( max == green ){
                hue = 120 + 60 * (blue - red) / (max - min);
            }
            else if( max == blue){
                hue = 240 + 60 * (red - green) / (max - min);
            }


            dst->data[pos_dst] = (unsigned char)( (hue * 255) / 360);
            dst->data[pos_dst + 1] = (unsigned char)(saturation * 255.0f);
            dst->data[pos_dst + 2] = (unsigned char)(value);

        }
    }

    return 1;
}


int vc_hsv_to_seg(IVC *src, IVC *dst){

    // Info da Source Image (src)
    unsigned char *datasrc = (unsigned char *) src->data;
    int bytesperline_src = src->width * src->channels;
    int channels_src = src->channels;

    // Info da Imagem Destino (dst)
    unsigned char *datadst = (unsigned char *) dst->data;
    int bytesperline_dst = dst->width * dst->channels;
    int channels_dst = dst->channels;

    // Width e Height da imagem Src
    int width = src->width; 
    int height = src->height;

    // Aux Variable
    int x, y;
    long int pos_src, pos_dst; 

    // Hsv floats
    float hue,saturation,value;

    // Verificação de erros
    if((src->width <= 0) || (src->height <= 0) || (src->data == NULL)) return 0; 
    if((src->width != dst->width) || (src->height != dst->height)) return 0;
    if((src->channels != 3) || (dst->channels != 1)) return 0;
    
    for (y = 0; y < height; y++){

        for (x = 0; x < width; x++){
            

            pos_src = y * bytesperline_src + x * channels_src; // Posição src
            pos_dst = y * bytesperline_dst + x * channels_dst; // Posição dst

            // // pegar na hue, saturation e value 
            hue = ((float) datasrc[pos_src] / 255) * 360; // hue
            saturation = (float) datasrc[pos_src + 1] / 255; // saturation
            value = (float) datasrc [pos_src + 2] / 255; // value

            // printf("%f",hue);
            if( 
                (hue >= 58 && hue <= 61) &&
                (saturation >= 0.81 && saturation <= 1) &&
                (value >= 0.87 && value <= 1) ){

                dst->data[pos_dst] = 255;
            }
            else{
                dst->data[pos_dst] = 0;
            }
           
        }
    }

    return 1;

}
