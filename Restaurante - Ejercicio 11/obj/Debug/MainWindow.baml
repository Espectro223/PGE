   M S B A M L   `   `   `  ����  Restaurante - Ejercicio 11    FoodExplorer.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	     � Title$  Explorador de Comida��5   	   $	��500��6&   $	��800��63    � 	Resources 5         CartAnimation �� 
TargetName �� TargetProperty �� From	 �� To g� Duration g� AutoReverse  CategoryTransitionAnimation W� From		 W� To��%w  &	        &	 �     �� 5   
   .��5	      �� $ AddToCartButton��6   $1 +(Button.Background).(SolidColorBrush.Color)�5
      $ 	LightGrayX�5      $ 
LightGreenX�6.   $ 0:0:0.3D�6>    . 6Q   5      �� 5   
   .��5      W� $ ProductList��6   $ Opacity�5      $	 1.0X�5      $		 0.0X�6   $ 0:0:0.3D�6&    . 69   5      5      .��5      � 
 � RowDefinitions
 5   
   �� 5      $
��Auto �6   �� 5      $��* �6   �� 5      $	��200 �6   .+�5   
   ��  �� Orientation$ 
Horizontal=�6   $��0��6.   
�������.+�5      �� -   5        $��🍔 Burger��5      $��10q�6)   $��5q�66   6A   �� 5      -   5        $��
🍕 Pizza��5      $��10q�6(   $��5q�65   6@   �� 5       -   5        $��🍰 Dessert��5       $��10q�6*   $��5q�67   6B   �� 5!      -   5        $��🍟 French��5!      $��10q�6)   $��5q�66   6A   �� 5"      -   5        $��🍹 Drinks��5"      $��10q�6)   $��5q�66   6A   �� 5#      -   5        $��🥡 Chinese��5#      $��10q�6*   $��5q�67   6B   5$      � 5'   
   $��1��6    � ColumnDefinitions 5(      �� 5)      $��2* �6#   �� 5*      $��3* �6#   �� 5+      $��2* �6#   .+�50      �� -   5        $��ProductList��50      $��0��6)   69   �� 53      $��1��6   $��10q�6+   $
��Auto=�67   .��54      �� .+�55      �� -   5        $��ProductImage��55      $	��200��60   $	��150��6<   $#��https://example.com/pizza.png��6I   �� 56      -	   5        $��ProductName��56       $
��Bold"�63   $��16(�6E   $��5q�6S   �� 57      $��	Opciones:��6    $
��Bold"�61   $��14(�6C   �� 59      -
   5        $��ProductOptions��59      �� 5<      $��Calificación:��6    $
��Bold"�65   $��5q�6G   �� 5=      $ 
Horizontal=�6!   .+�5?      �� -   5        $��Star1��5?   !   
 � Tag$ 1��6A   .��5@      �� -   5        $��
StarImage1��5@   $   $Z��TD:/Usuario Lab/Descargas/PGE-main/Restaurante - Ejercicio 11/Imagenes/star_empty.png��66   $��20��6�   5A      �� 5B      -   5        $��Star2��5B   !   $ 2��6A   .��5C      �� -   5        $��
StarImage2��5C   $   $Z��TD:/Usuario Lab/Descargas/PGE-main/Restaurante - Ejercicio 11/Imagenes/star_empty.png��66   $��20��6�   5D      �� 5E      -   5        $��Star3��5E   !   $ 3��6A   .��5F      �� -   5        $��
StarImage3��5F   $   $Z��TD:/Usuario Lab/Descargas/PGE-main/Restaurante - Ejercicio 11/Imagenes/star_empty.png��66   $��20��6�   5G      �� 5H      -   5        $��Star4��5H   !   $ 4��6A   .��5I      �� -   5        $��
StarImage4��5I   $   $Z��TD:/Usuario Lab/Descargas/PGE-main/Restaurante - Ejercicio 11/Imagenes/star_empty.png��66   $��20��6�   5J      �� 5K      -   5        $��Star5��5K   !   $ 5��6A   .��5L      �� -   5        $��
StarImage5��5L   $   $Z��TD:/Usuario Lab/Descargas/PGE-main/Restaurante - Ejercicio 11/Imagenes/star_empty.png��66   $��20��6�   5M      5N      �� 5Q      $��Calificación promedio:��6    $
��Bold"�6>   $��5q�6P   �� 5R      -   5        $��AverageRatingText��5R       $��14(�69   $��5q�6G   �� 5U      -   5        $��AddToCartButton��5U      $��Agregar al Carrito��64   $��10q�6i   
�������6u   �� 5X      -   5        $��Ver Resumen de Compra��5X      $��10q�6W   �� 5[      -   5        $��Borrar Calificación��5[      $��10q�6U   �� 5^      -   5        $��Mostrar Mapa��5^      $��10q�6J   5_      5`      �� 5c      $��2��6   $��10q�6)   
�������.+�5d      �� $��Carrito de Compras��6   $
��Bold"�66   $��16(�6H   $��5q�6V   �� 5e      -   5        $��CartListBox��5e      $	��300��6-   $	��250��6:   �� 5f      -   5        $��Eliminar del Carrito��5f      $��10q�6U   5g      5h      �� 5k      $��2��6   
����ح�$��10q�61   ._�5l   
   �� $�� ��6   $��Center=�6   $��Center=�67   5m      5n      5o      