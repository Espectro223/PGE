using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculadora
{
    public partial class Calculadora : Form
    {

        private decimal _operando;
        private string _operandoTxt;
        private string _operador;

        public Calculadora()
        {
            InitializeComponent();
        }


        private void setOperandoTxt(string valor)
        {

            if(valor == "0" || valor == "1" || valor == "2" || valor == "3" || valor == "4" || valor == "5"
                || valor == "6" || valor == "7" || valor == "8" || valor == "9")
            {
                _operandoTxt = _operandoTxt + valor;
                textBox1.Text = _operandoTxt;
            }
            else if(valor == "+" || valor == "-" || valor == "/" || valor == "*")
            {
                _operador = valor; 
                _operando = decimal.Parse(_operandoTxt);
                _operandoTxt = "";
            }
        }

        private void DoOperacion()
        {

            decimal resultado = 0;
            if(_operador == "+")
            {
                resultado = _operando + decimal.Parse(_operandoTxt);
            }
            else if(_operador == "-")
            {
                resultado = _operando - decimal.Parse(_operandoTxt);
            }
            else if(_operador == "*")
            {
                resultado = _operando * decimal.Parse(_operandoTxt);
            }
            else if(_operador == "/")
            {
                resultado = _operando / decimal.Parse(_operandoTxt);
            }

            textBox1.Text = resultado.ToString();
        }

        private void Delete()
        {
            if (!string.IsNullOrEmpty(_operandoTxt))
            {
                _operandoTxt = _operandoTxt.Substring(0, _operandoTxt.Length - 1);
                textBox1.Text = _operandoTxt;
            }
        }

        private void C()
        {
            _operando = 0;
            _operandoTxt = "";
            _operador = "";
            textBox1.Text = "";
        }
        private void button1_Click(object sender, EventArgs e)
        {
            setOperandoTxt("1");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            setOperandoTxt("2");
        }

        private void btnNumero3_Click(object sender, EventArgs e)
        {
            setOperandoTxt("3");
        }

        private void btnNumero4_Click(object sender, EventArgs e)
        {
            setOperandoTxt("4");
        }

        private void btnNumero5_Click(object sender, EventArgs e)
        {
            setOperandoTxt("5");
        }

        private void btnNumero6_Click(object sender, EventArgs e)
        {
            setOperandoTxt("6");
        }

        private void btnNumero7_Click(object sender, EventArgs e)
        {
            setOperandoTxt("7");
        }

        private void btnNumero8_Click(object sender, EventArgs e)
        {
            setOperandoTxt("8");
        }

        private void btnNumero9_Click(object sender, EventArgs e)
        {
            setOperandoTxt("9");
        }

        private void btnNumero0_Click(object sender, EventArgs e)
        {
            setOperandoTxt("0");
        }

        private void Calculadora_KeyPress(object sender, KeyPressEventArgs e)
        {
            setOperandoTxt(e.KeyChar.ToString());
        }

        private void btnSumar_Click(object sender, EventArgs e)
        {
            setOperandoTxt("+");
        }

        private void btnIgual_Click(object sender, EventArgs e)
        {
            DoOperacion();
        }

        private void btnRestar_Click(object sender, EventArgs e)
        {
            setOperandoTxt("-");
        }

        private void btnMultiplicar_Click(object sender, EventArgs e)
        {
            setOperandoTxt("*");
        }

        private void btnDividir_Click(object sender, EventArgs e)
        {
            setOperandoTxt("/");
        }

        private void btnBorrar_Click(object sender, EventArgs e)
        {
            Delete();
        }

        private void btnC_Click(object sender, EventArgs e)
        {
            C();
        }
    }
}
