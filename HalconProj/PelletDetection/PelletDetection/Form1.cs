using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PelletDetection
{
	public partial class Form1 : Form
	{
		HDevelopExport HDevelop = new HDevelopExport();
		public Form1()
		{
			InitializeComponent();
		}

		private void Button1_Click(object sender, EventArgs e)
		{
			HDevelop.RunHalcon(hWindowControl1.HalconWindow);
		}

		private void HWindowControl1_HMouseMove(object sender, HalconDotNet.HMouseEventArgs e)
		{

		}
	}
}
