using System;
using System.Windows;
using Microsoft.Phone.Controls;

namespace CSUSBMobile {
    public partial class MainPage : PhoneApplicationPage {

        // Constructor
        public MainPage() {
            InitializeComponent();
<<<<<<< .mine

            string site = "https://tinyurl.com/csusbmobile";
=======
            webBrowser1.IsScriptEnabled = true;
            string site = "http://mobile.dev.ias.csusb.edu/WebView/index.php";
>>>>>>> .r116
            webBrowser1.Navigate(new Uri(site, UriKind.Absolute));
        }
    }
}
