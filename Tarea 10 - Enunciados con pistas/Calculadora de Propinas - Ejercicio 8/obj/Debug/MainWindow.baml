   M S B A M L   `   `   `  ����)  %Calculadora de Propinas - Ejercicio 8!    TipCalculatorApp.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	     � Title$  Calculadora de Propinas��5   	   $	��300��6)   $	��400��66   ���#FFFAF3.��5      � $��10q�6   .+�5   
   �� $��Monto Total de la Cuenta:��6   $
��Left=�64   $	��Top=�6O   $��14(�6g   �� 5	   
   -   5         ��Name$ MontoTextBox��5	      $
��Left=�6(   $	��150��6C   $��	10,30,0,0q�6O   $	��Top=�6b   $��14(�6z   �� 5   
   $��Porcentaje de Propina:��6   $
��Left=�61   $	��Top=�6L   $��14(�6d   $��	10,70,0,0q�6r   �� 5   
   -   5         ��Name$ PropinaSlider��5       � Minimum$ 5Q�6(    � Maximum$ 30Q�64    � Value$ 15Q�6A   $	��200��6L   $
��Left=�6X   $��
10,100,0,0q�6s   $	��Top=�6�   �� 5   
   $
��Left=�6c   $��220,100,0,0q�6~   $	��Top=�6�   $��14(�6�   ��6   ��  �� ElementName$ PropinaSlider�� �� Path$ Value� �� StringFormat$ {0:F0}%��6�   �� 5   
   -   5        $��Calcular Propina��5      $
��Left=�6,   $	��150��6G   $��
10,150,0,0q�6S   $	��Top=�6g   $��14(�6�   ���#FF6347
�������6�   �� 5   
   -   5        	 ��Name$	 ResultadoTextBlock��5      $
��Left=�60   $	��Top=�6K   $��
10,200,0,0q�6c   $��14(�6w   $	��350��6�   $
��Wrap=�6�   ���#2E8B576�   5      5      