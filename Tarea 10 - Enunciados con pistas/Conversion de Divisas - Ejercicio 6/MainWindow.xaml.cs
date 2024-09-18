using Microsoft.Win32;
using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.IO;

namespace ImageEditorApp
{
    public partial class MainWindow : Window
    {
        private BitmapImage originalImage; // Imagen original cargada
        private WriteableBitmap editedImage; // Imagen que será editada

        public MainWindow()
        {
            InitializeComponent();
        }

        // Método para cargar la imagen
        private void CargarImagen_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Image files (*.jpg, *.png)|*.jpg;*.png";

            if (openFileDialog.ShowDialog() == true)
            {
                originalImage = new BitmapImage(new Uri(openFileDialog.FileName));
                ImagenControl.Source = originalImage;
                editedImage = new WriteableBitmap(originalImage);
            }
        }

        // Evento para previsualizar cambios al ajustar el slider de tamaño
        private void TamañoSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (originalImage == null) return;

            // Mostrar el valor actual del tamaño en el TextBlock
            TamañoValueTextBlock.Text = $"{(int)TamañoSlider.Value}%";

            // Aplicar el cambio de tamaño en tiempo real
            double scale = TamañoSlider.Value / 100.0;
            TransformGroup transformGroup = new TransformGroup();
            transformGroup.Children.Add(new ScaleTransform(scale, scale));
            ImagenControl.Source = new TransformedBitmap(originalImage, transformGroup);
        }

        // Evento para previsualizar cambios al ajustar el slider de brillo
        private void BrilloSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (originalImage == null) return;

            // Mostrar el valor actual del brillo en el TextBlock
            BrilloValueTextBlock.Text = $"{BrilloSlider.Value:F2}";

            // Aplicar el cambio de brillo en tiempo real
            double brightness = BrilloSlider.Value;
            editedImage = AdjustBrightness(originalImage, brightness);
            ImagenControl.Source = editedImage;
        }

        // Método personalizado de clamping
        private int Clamp(int value, int min, int max)
        {
            if (value < min) return min;
            if (value > max) return max;
            return value;
        }

        // Método para ajustar el brillo
        private WriteableBitmap AdjustBrightness(BitmapSource image, double brightness)
        {
            var wb = new WriteableBitmap(image);
            int width = wb.PixelWidth;
            int height = wb.PixelHeight;
            int stride = width * ((wb.Format.BitsPerPixel + 7) / 8);
            byte[] pixelData = new byte[height * stride];
            wb.CopyPixels(pixelData, stride, 0);

            for (int i = 0; i < pixelData.Length; i += 4) // BGR format
            {
                for (int j = 0; j < 3; j++) // Ajustamos RGB (no alfa)
                {
                    int value = pixelData[i + j] + (int)(brightness * 255);
                    pixelData[i + j] = (byte)Clamp(value, 0, 255);
                }
            }

            wb.WritePixels(new Int32Rect(0, 0, width, height), pixelData, stride, 0);
            return wb;
        }

        // Método para guardar la imagen editada
        private void GuardarImagen_Click(object sender, RoutedEventArgs e)
        {
            if (editedImage == null) return;

            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "PNG Image|*.png|JPEG Image|*.jpg";

            if (saveFileDialog.ShowDialog() == true)
            {
                using (FileStream stream = new FileStream(saveFileDialog.FileName, FileMode.Create))
                {
                    BitmapEncoder encoder = null;
                    if (saveFileDialog.FilterIndex == 1)
                        encoder = new PngBitmapEncoder();
                    else if (saveFileDialog.FilterIndex == 2)
                        encoder = new JpegBitmapEncoder();

                    encoder.Frames.Add(BitmapFrame.Create(editedImage));
                    encoder.Save(stream);
                }
            }
        }

        private void AplicarCambios_Click(object sender, RoutedEventArgs e)
        {
            // Aquí colocamos la lógica que se aplica cuando se presiona el botón "Aplicar Cambios"
            if (originalImage == null) return;

            // Ajustar tamaño
            double scale = TamañoSlider.Value / 100.0;
            TransformGroup transformGroup = new TransformGroup();
            transformGroup.Children.Add(new ScaleTransform(scale, scale));

            // Aplicar ajustes de brillo
            double brightness = BrilloSlider.Value;
            editedImage = AdjustBrightness(originalImage, brightness);

            ImagenControl.Source = new TransformedBitmap(editedImage, transformGroup);
        }

    }
}
