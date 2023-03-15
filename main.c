#include <stdio.h> 
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main (void)
{
    IVC *image; 
    int i;
    
    if (image == NULL){
        printf("ERROR -> vc_read_image():\n\tFile not found! \n");
        getchar();
        return 0;
    }

    // // Converter para Cor sólida
    // for (i = 0; i <= 3; i++)
    // {
    //     image = vc_read_image("./Images/Additional/flowers.ppm");

    //     if(i == 1){
    //         vc_rgb_get_red(image);
    //         vc_write_image("red.ppm", image); // Write the image with the filename
    //     }
    //     else if(i == 2){
    //         vc_rgb_get_green(image);
    //         vc_write_image("green.ppm", image); // Write the image with the filename
    //     }
    //     else{
    //         vc_rgb_get_blue(image);
    //         vc_write_image("blue.ppm", image); // Write the image with the filename
    //     }
    
    // }
    

    // // Converter as cores para Grayscale
    // for (i = 0; i <= 3; i++)
    // {
        

    //     if(i == 1){
    //         image = vc_read_image("./red.ppm");
    //         vc_rgb_get_red_gray(image);
    //         vc_write_image("red_gray.ppm", image); // Write the image with the filename
    //     }
    //     else if(i == 2){
    //         image = vc_read_image("./green.ppm");
    //         vc_rgb_get_green_gray(image);
    //         vc_write_image("green_gray.ppm", image); // Write the image with the filename
    //     }
    //     else{
    //         image = vc_read_image("./blue.ppm");
    //         vc_rgb_get_blue_gray(image);
    //         vc_write_image("blue_gray.ppm", image); // Write the image with the filename
    //     }
    
    // }



    // RGB To gray
    // image = vc_read_image("./HSVTestImage01.ppm");

    // IVC* auxImg;
    // auxImg = vc_image_new(image->width,image->height,3,image->levels);

    // // vc_rgb_to_gray(image,auxImg);
    // vc_rgb_to_hsv(image,auxImg);
    // vc_write_image("./hsv.ppm", auxImg); // Write the image with the filename

    // vc_image_free(image);

    // HSV -> SEG
    // IVC* ImgHSV;
    // IVC* AuxImgHSV;
    // ImgHSV = vc_read_image("./hsv.ppm");
    // AuxImgHSV = vc_image_new(ImgHSV->width,ImgHSV->height,1,ImgHSV->levels);

    // vc_hsv_to_seg(ImgHSV,AuxImgHSV);
    // vc_write_image("./fruitsseg.ppm", AuxImgHSV); // Write the image with the filename

    // vc_image_free(ImgHSV);
    // vc_image_free(AuxImgHSV);


    /**
     * @brief Converter uma imagem de PGM 1 Channel para 3 Channels RGB
     */
    IVC* ImgGrayscale;
    IVC* AuxImgRGB;
    ImgGrayscale = vc_read_image("./Images/FLIR/flir-04.pgm");
    AuxImgRGB = vc_image_new(ImgGrayscale->width,ImgGrayscale->height,3,ImgGrayscale->levels);

    vc_scale_gray_to_rgb(ImgGrayscale,AuxImgRGB);
    vc_write_image("./ImagensGeradas/GrayscaleRGB/grayscaleRGB.ppm", AuxImgRGB); // Write the image with the filename

    vc_image_free(ImgGrayscale);
    vc_image_free(AuxImgRGB);

    printf("Press any key to exit... In");
    getchar();

    return 0;
}