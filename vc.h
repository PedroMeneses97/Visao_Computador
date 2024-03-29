//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           INSTITUTO POLIT�CNICO DO C�VADO E DO AVE
//                          2022/2023
//             ENGENHARIA DE SISTEMAS INFORM�TICOS
//                    VIS�O POR COMPUTADOR
//
//             [  BRUNO OLIVEIRA - boliveira@ipca.pt  ]
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define VC_DEBUG


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   ESTRUTURA DE UMA IMAGEM
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


typedef struct {
	unsigned char *data;
	int width, height;
	int channels;			// Binário/Cinzentos=1; RGB=3
	int levels;				// Binário=1; Cinzentos [1,255]; RGB [1,255]
	int bytesperline;		// width * channels
} IVC;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                    PROT�TIPOS DE FUN��ES
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// FUN��ES: ALOCAR E LIBERTAR UMA IMAGEM
IVC *vc_image_new(int width, int height, int channels, int levels);
IVC *vc_image_free(IVC *image);

// FUN��ES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
IVC *vc_read_image(char *filename);
int vc_write_image(char *filename, IVC *image);

int vc_gray_negative(IVC *srcdst);
int vc_rgb_negative(IVC *srcdst);


// Espaços de cor
int vc_rgb_get_red_gray(IVC *srcdst);
int vc_rgb_get_red(IVC *srcdst);

int vc_rgb_get_green_gray(IVC *srcdst);
int vc_rgb_get_green(IVC *srcdst);


int vc_rgb_get_blue_gray(IVC *srcdst);
int vc_rgb_get_blue(IVC *srcdst);


// RGB em tons de cinzento
int vc_rgb_to_gray(IVC *src, IVC *dst);


int vc_rgb_to_hsv(IVC *src, IVC *dst);

// HSV to Segmentation
int vc_hsv_to_seg(IVC *src, IVC *dst);

// Gray to RGB
int vc_scale_gray_to_rgb(IVC *src, IVC *dst);


int vc_gray_to_binary(IVC *src, IVC *dst, int threshold);

int threshold_media(IVC *src, IVC *dst);