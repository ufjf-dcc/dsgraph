using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Xml;
using System.Text;
using System.IO;
using System.Net;
using ICSharpCode.SharpZipLib.Zip;
using System.Windows.Forms;

namespace DSGraph
{
    public partial class frm : Form
    {
        public frm()
        {
            InitializeComponent();
        }

        //Pasta de Suporte para os arquivos de Download
        private String PATH_DSGRAPH_DOWNLOAD = @"c:\temp";
        //Dll da Allegro
        private String URL_ALLEGRO_DLL = "http://www.allegro.cc/files/4.2.2/alleg42.dll";
        //Biblioteca da Allegro
        private String URL_ALLEGRO_LIB = "http://static.allegro.cc/file/library/allegro/4.4.2/allegro-4.4.2-mingw-4.5.2.zip";
        //CodeBlocks
        private String URL_CODEBLOCKS = "https://sourceforge.net/projects/codeblocks/files/Binaries/10.05/Windows/codeblocks-10.05mingw-setup.exe/download";
        //DSGraph
        private String URL_DSGRAPH = "https://sourceforge.net/projects/dsgraph/files/compilado/instalador/dsgraph_4win_32_64_bits.zip/download";

        private String URL_EXEMPLOS = "https://sourceforge.net/projects/dsgraph/files/compilado/instalador/ExemplosDSGraph.zip/download";

        //Arquitetura do SO
        private String SO_64_BITS = "AMD64";
        private String PATH_CODEBLOCKS = "";
        private static ProgressBar pb;
        private static Form me;


        private void btnSair_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }


        /**
         * Cria as variáveis de ambiente
         */
        private void criarVariaveisAmbiente()
        {

            setMensagem("Criando variáveis de ambiente...");
            textMsgs.Text += "\nCriando a variável de ambiente MINGDIR...";
            //Criando a variável de ambiente para o MinGW
            Environment.SetEnvironmentVariable("MINGDIR", PATH_CODEBLOCKS + @"\MinGW\bin", EnvironmentVariableTarget.Machine);
            textMsgs.Text += "\nSetando a pasta MINGDIR no Path...";
            String PATH = Environment.GetEnvironmentVariable("Path");
            Environment.SetEnvironmentVariable("Path", @"%MINGDIR%;", EnvironmentVariableTarget.User);
            setMensagem("Variáveis de ambiente criadas com sucesso!");

        }

        /**
         * Verifica se a pasta de suporte está disponível. Caso não está, cria.
         * */
        private void verificaPastaDownload()
        {
            setMensagem("Verificando a pasta de suporte para download...");
            if (!Directory.Exists(PATH_DSGRAPH_DOWNLOAD))
                Directory.CreateDirectory(PATH_DSGRAPH_DOWNLOAD);
        }

        /**
         * Adiciona a mensagem na caixa de texto
         */
        private void setMensagem(String mensagem)
        {
            this.Refresh();
            textMsgs.Text += mensagem + "\r\n";
            textMsgs.SelectionStart = textMsgs.Text.Length;
            textMsgs.ScrollToCaret();
            textMsgs.Refresh();
            Application.DoEvents();

        }

        /**
         * Faz o download da DSGraph
         */
        private void downloadDSGraph()
        {
            setProgressBarValue(0);
            setProgressBarValue(100);
            Application.DoEvents();
            WebClient client = new WebClient();
            setMensagem("Efetuando o download da DSGraph");
            if (File.Exists(PATH_DSGRAPH_DOWNLOAD + "\\dsgraph.zip"))
            {
                File.Delete(PATH_DSGRAPH_DOWNLOAD + "\\dsgraph.zip");
            }
            client.DownloadFile(new Uri(URL_DSGRAPH), PATH_DSGRAPH_DOWNLOAD + "\\dsgraph.zip");

            setMensagem("Download da DSGraph concluído");
        }


        /**
         * Faz o download dos exemplos
         */
        private void downloadExemplos()
        {
            setProgressBarValue(0);
            setProgressBarValue(100);
            Application.DoEvents();
            WebClient client = new WebClient();
            setMensagem("Efetuando o download dos exemplos....");
            if (File.Exists(PATH_DSGRAPH_DOWNLOAD + "\\exemplos.zip"))
            {
                File.Delete(PATH_DSGRAPH_DOWNLOAD + "\\exemplos.zip");
            }
            client.DownloadFile(new Uri(URL_EXEMPLOS), PATH_DSGRAPH_DOWNLOAD + "\\exemplos.zip");

            setMensagem("Download dos exemplos concluído");
        }


        /**
         * Após finalizar o Download do CodeBlocks
         * */
        private void posDownloadCodeBlocks(object sender, AsyncCompletedEventArgs e)
        {
            try
            {
                downloadAllegro();
            }
            catch
            {
                msgBox("Download da Allegro");
                return;
            }

        }

        /**
         * Após finalizar o download da Allegro
         * */
        private void posDownloadAllegro(object sender, AsyncCompletedEventArgs e)
        {
            setMensagem("Download da Biblioteca Allegro concluído");


            try
            {
                downloadDSGraph();
            }
            catch
            {
                msgBox("Download da DSGraph");
                return;
            }

            try
            {

                downloadExemplos();
            }
            catch
            {
                msgBox("Download dos exemplos");
                return;
            }


            try
            {
                //Instalar o CodeBlocks?!
                if (chkCodeBlocks.Checked)
                    instalarCodeBlocks();
            }
            catch
            {
                msgBox("Instalação do CodeBlocks");
                return;
            }

            try
            {
                localizarCodeBlocks(@"C:\");
            }
            catch
            {
                msgBox("Localizando a instalação do CodeBlocks");
                return;
            }


            if (PATH_CODEBLOCKS != "")
            {

                /* try
                 {
                     criarVariaveisAmbiente();
                 }
                 catch
                 {
                     msgBox("Criando variáveis de ambiente...");
                     return;
                 }*/

                try
                {
                    descompactCopyLibAllegro();
                }
                catch
                {
                    msgBox("Descompactando os arquivos da Allegro");
                    return;
                }


                try
                {
                    descompactCopyDSGraphLib();
                }
                catch
                {
                    msgBox("Descompactando os arquivos da DSGraph");
                    return;
                }

                try
                {
                    descompactExemplos();
                }
                catch
                {
                    msgBox("Descompactando os exemplos");
                    return;
                }

                try
                {
                    copyDll();
                }
                catch
                {
                    msgBox("Efetuando a cópia das DLL's");
                    return;
                }
            }

            setMensagem("Instalação/Configuração concluída com exito!");
            MessageBox.Show("Instalação concluída com sucesso!", "DSGraph", MessageBoxButtons.OK, MessageBoxIcon.Information);

            configuraProjetoCodeBlocks();

            iniciarCodeBlocks();

            btnInstall.Enabled = true;
            btnAtualizar.Enabled = true;
            this.UseWaitCursor = false;


        }

        /**
         * Faz o download do CodeBlocks com o MinGW
         */
        private void downloadCodeBlocks()
        {
            setProgressBarValue(0);
            WebClient client = new WebClient();
            setMensagem("Efetuando o download do CodeBlocks (75 mb aprox)...");
            if (!File.Exists(PATH_DSGRAPH_DOWNLOAD + "\\codeblocks-10.05mingw-setup.exe"))
            {
                client.DownloadProgressChanged += new DownloadProgressChangedEventHandler(DownloadProgressCallback);
                client.DownloadFileCompleted += new AsyncCompletedEventHandler(posDownloadCodeBlocks);
                client.DownloadFileAsync(new Uri(URL_CODEBLOCKS), PATH_DSGRAPH_DOWNLOAD + "\\codeblocks-10.05mingw-setup.exe");
            }
            else
            {
                setProgressBarValue(100);
                posDownloadCodeBlocks(null, null);
            }

        }

        /**
         * Seta o progress bar
         * */
        private static void setProgressBarValue(int value)
        {
            pb.Value = value;
            pb.Refresh();
            Application.DoEvents();
        }

        /**
         * Atualiza a barra de progresso e força um Doevents para liberar renderização para o sistema operacional
         * e outras coisas
         * */
        private static void DownloadProgressCallback(object sender, DownloadProgressChangedEventArgs e)
        {
            setProgressBarValue(e.ProgressPercentage);
            Application.DoEvents();
        }

        /**
         * Faz o download da Allegro
         */
        private void downloadAllegro()
        {
            setMensagem("Efetuando os downloads dos arquivos da Allegro...");
            WebClient client = new WebClient();
            setMensagem("Efetuando o download da alleg42.dll...");
            if (!File.Exists(PATH_DSGRAPH_DOWNLOAD + "\\alleg42.dll"))
            {
                client.DownloadFile(new Uri(URL_ALLEGRO_DLL), PATH_DSGRAPH_DOWNLOAD + "\\alleg42.dll");
            }
            setMensagem("Download da alleg42.dll concluído!");

            setMensagem("Efetuando o download da Biblioteca Allegro(22 mb aprox)...");
            setProgressBarValue(0);
            if (!File.Exists(PATH_DSGRAPH_DOWNLOAD + "\\allegro-4.4.2-mingw-4.5.2.zip"))
            {
                client.DownloadProgressChanged += new DownloadProgressChangedEventHandler(DownloadProgressCallback);
                client.DownloadFileCompleted += new AsyncCompletedEventHandler(posDownloadAllegro);
                client.DownloadFileAsync(new Uri(URL_ALLEGRO_LIB), PATH_DSGRAPH_DOWNLOAD + "\\allegro-4.4.2-mingw-4.5.2.zip");
            }
            else
            {
                setProgressBarValue(100);
                posDownloadAllegro(null, null);

            }


        }

        /**
         * Copia a DLL para o ambiente
         */
        private void copyDll()
        {

            setMensagem("Copiando as DLL'S...");

            if (SO_64_BITS.Equals(System.Environment.GetEnvironmentVariable("PROCESSOR_ARCHITECTURE")))
            {

                if (File.Exists(@"C:\Windows\SysWOW64\alleg42.dll"))
                    File.Delete(@"C:\Windows\SysWOW64\alleg42.dll");

                if (File.Exists(@"C:\Windows\SysWOW64\allegro-4.4.2-monolith-mt.dll"))
                    File.Delete(@"C:\Windows\SysWOW64\allegro-4.4.2-monolith-mt.dll");


                //Copia a dll para -> C:\Windows\SysWOW64
                File.Copy(PATH_DSGRAPH_DOWNLOAD + "\\alleg42.dll", @"C:\Windows\SysWOW64\alleg42.dll");
                File.Copy(PATH_CODEBLOCKS + @"\MinGW\allegro-4.4.2-mingw-4.5.2\bin\allegro-4.4.2-monolith-mt.dll", @"C:\Windows\SysWOW64\allegro-4.4.2-monolith-mt.dll");

            }
            else
            {

                if (File.Exists(@"C:\Windows\System32\alleg42.dll"))
                    File.Delete(@"C:\Windows\System32\alleg42.dll");

                if (File.Exists(@"C:\Windows\System32\allegro-4.4.2-monolith-mt.dll"))
                    File.Delete(@"C:\Windows\System32\allegro-4.4.2-monolith-mt.dll");

                //Copia a dll para C:\Windows\System32
                File.Copy(PATH_DSGRAPH_DOWNLOAD + "\\alleg42.dll", @"C:\Windows\System32\alleg42.dll");
                File.Copy(PATH_CODEBLOCKS + @"\MinGW\allegro-4.4.2-mingw-4.5.2\bin\allegro-4.4.2-monolith-mt.dll", @"C:\Windows\System32\allegro-4.4.2-monolith-mt.dll");


            }

            setMensagem("DLL's copiadas com sucesso!");

        }
        /**
         * Descompacta e copia a AllegroLIB para o Mingw
         * */
        private void descompactCopyLibAllegro()
        {

            setMensagem("Descompactando os arquivos da Allegro...");

            FastZip fz = new FastZip();
            fz.ExtractZip(PATH_DSGRAPH_DOWNLOAD + "\\allegro-4.4.2-mingw-4.5.2.zip", PATH_CODEBLOCKS + @"\MinGW\", "");
            setMensagem("Descompactado com sucesso");

        }

        /**
         * Descompacta os exemplos da DSGraph
         * */
        private void descompactExemplos()
        {

            setMensagem("Descompactando os exemplos...");

            FastZip fz = new FastZip();
            fz.ExtractZip(PATH_DSGRAPH_DOWNLOAD + "\\exemplos.zip", PATH_DSGRAPH_DOWNLOAD, "");
            setMensagem("Descompactado com sucesso");

        }


        /**
         * Descompacta os arquivos da DSGraph
         * */
        private void descompactCopyDSGraphLib()
        {
            setMensagem("Descompactando os arquivos da DSGraph...");

            FastZip fz = new FastZip();

            fz.ExtractZip(PATH_DSGRAPH_DOWNLOAD + "\\dsgraph.zip", PATH_CODEBLOCKS + @"\MinGW\lib", "");

            if (File.Exists(PATH_CODEBLOCKS + @"\MinGW\lib\DSGraph.h"))
            {

                if (File.Exists(PATH_CODEBLOCKS + @"\MinGW\include\DSGraph.h"))
                    File.Delete(PATH_CODEBLOCKS + @"\MinGW\include\DSGraph.h");

                File.Copy(PATH_CODEBLOCKS + @"\MinGW\lib\DSGraph.h", PATH_CODEBLOCKS + @"\MinGW\include\DSGraph.h");
            }

            setMensagem("Descompactado com sucesso");


        }


        /**
         * Busca a pasta de instalação do CodeBlocks
         */
        private void localizarCodeBlocks(string sDir)
        {

            setMensagem("Localizando os arquivos de instalação do CodeBlocks...");

            if (File.Exists(@"c:\Arquivos de Programas\CodeBlocks\codeblocks.exe"))
            {
                PATH_CODEBLOCKS = @"c:\Arquivos de Programas\CodeBlocks\";
                return;
            }

            if (File.Exists(@"c:\Program Files\CodeBlocks\codeblocks.exe"))
            {
                PATH_CODEBLOCKS = @"c:\Program Files\CodeBlocks\";
                return;
            }

            if (File.Exists(@"C:\Program Files (x86)\CodeBlocks\codeblocks.exe"))
            {
                PATH_CODEBLOCKS = @"C:\Program Files (x86)\CodeBlocks\";
                return;
            }

            if (File.Exists(@"C:\CodeBlocks\codeblocks.exe"))
            {
                PATH_CODEBLOCKS = @"C:\CodeBlocks\";
                return;
            }


            MessageBox.Show("Não foi possível localizar o CodeBlocks. Sem o mesmo, o instalador irá ser cancelado." +
                            "\nPor favor, indique onde o mesmo foi instalado", "DSGraph", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);

            openFileDialog.InitialDirectory = sDir;
            openFileDialog.Filter = "CodeBlocks (.EXE)|(*.exe)";


            openFileDialog.ShowDialog();

            String arquivo = openFileDialog.FileName;

            if (arquivo != null && arquivo.IndexOf("codeblocks.exe") > 1)
            {
                PATH_CODEBLOCKS = arquivo.Substring(0, arquivo.Length - 15);
            }
            else
            {
                PATH_CODEBLOCKS = "";
            }

        }

        /**
         * Configura os exemplos do CodeBlocks
         * */
        private void configuraProjetoCodeBlocks()
        {

            try
            {
                String[] pastas = Directory.GetDirectories(PATH_DSGRAPH_DOWNLOAD + "\\ExemplosDSGraph");

                foreach (string subpasta in pastas)
                {

                    String projeto = subpasta.Replace(PATH_DSGRAPH_DOWNLOAD + "\\ExemplosDSGraph", "");
                    projeto = projeto.Replace("\\", "");

                    StreamWriter arq = new StreamWriter(subpasta + "\\" + projeto + ".cbp", true, Encoding.ASCII);
                    arq.Write(getCBPFile(projeto));
                    arq.Close();

                }
            }
            catch(Exception ex)
            {
                setMensagem("Erro:" + ex.StackTrace);
                msgBox("Configuração dos projetos");
            }


        }
        
        /**
         * Retorna o arquivo do projeto
         * [ESTE MÉTODO PRECISA SER REFATORADO UTILIZANDO AS CLASSES XML do C#]
         */
        private String getCBPFile(String projeto)
        {
            String result = "";

            result += "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>\n";
            result += "<CodeBlocks_project_file>\n";
            result += "<FileVersion major=\"1\" minor=\"6\" />\n";
            result += "<Project>\n";
            result += "<Option title=\"" + projeto + "\" />\n";
            result += "<Option pch_mode=\"2\" />\n";
            result += "<Option compiler=\"gcc\" />\n";
            result += "<Build>\n";
            result += "<Target title=\"Debug\">\n";
            result += "	<Option output=\"bin\\Debug\\" + projeto + "\" prefix_auto=\"1\" extension_auto=\"1\" />\n";
            result += "	<Option object_output=\"obj\\Debug\" />\n";
            result += "	<Option type=\"1\" />\n";
            result += "	<Option compiler=\"gcc\" />\n";
            result += "	<Compiler>\n";
            result += "		<Add option=\"-g\" />\n";
            result += "	</Compiler>\n";
            result += "</Target>\n";
            result += "<Target title=\"Release\">\n";
            result += "	<Option output=\"bin\\Release\\" + projeto + "\" prefix_auto=\"1\" extension_auto=\"1\" />\n";
            result += "	<Option object_output=\"obj\\Release\" />\n";
            result += "	<Option type=\"1\" />\n";
            result += "	<Option compiler=\"gcc\" />\n";
            result += "	<Compiler>\n";
            result += "		<Add option=\"-O2\" />\n";
            result += "	</Compiler>\n";
            result += "	<Linker>\n";
            result += "		<Add option=\"-s\" />\n";
            result += "	</Linker>\n";
            result += "</Target>\n";
            result += "</Build>\n";
            result += "<Compiler>\n";
            result += "<Add option=\"" + "-Wall" + " \"/>\n";
            result += "  <Add directory=\"" + PATH_CODEBLOCKS + "\\MinGW\\include\" />\n";
            result += "  <Add directory=\"" + PATH_CODEBLOCKS + "\\MinGW\\allegro-4.4.2-mingw-4.5.2\\include\" />\n";
            result += "</Compiler>\n";
            result += "<ResourceCompiler>\n";
            result += "	<Add directory=\" " + PATH_CODEBLOCKS + "\\MinGW\\include\" />\n";
            result += "</ResourceCompiler>\n";
            result += "<Linker>\n";
            result += "	<Add library=\"" + PATH_CODEBLOCKS + "\\MinGW\\lib\\DSGraph_LIB.a\" />\n";
            result += "	<Add library=\"" + PATH_CODEBLOCKS + "\\MinGW\\allegro-4.4.2-mingw-4.5.2\\lib\\liballegro-4.4.2-monolith-mt.a\" />\n";
            result += "	<Add directory=\"" + PATH_CODEBLOCKS + "\\MinGW\\lib\" />\n";
            result += "	<Add directory=\"" + PATH_CODEBLOCKS + "\\MinGW\\allegro-4.4.2-mingw-4.5.2\\lib\" />\n";
            result += "</Linker>\n";
            result += "<Unit filename=\"main.c\">\n";
            result += "<Option compilerVar=\"CC\" />\n";
            result += "</Unit>\n";
            result += "<Extensions>\n";
            result += "<code_completion />\n";
            result += "<envvars />\n";
            result += "<debugger />\n";
            result += "<lib_finder disable_auto=\"1\" />\n";
            result += "</Extensions>\n";
            result += "</Project>\n";
            result += "</CodeBlocks_project_file>\n";

            return result;
        }

        /**
         * Inicializa o workspace de Exemplos com o CodeBlocks
         * */
        private void iniciarCodeBlocks()
        {
            try
            {
                Process codeblocks = new Process();
                codeblocks.StartInfo.FileName = PATH_DSGRAPH_DOWNLOAD + "\\ExemplosDSGraph\\exemplos.workspace";
                codeblocks.StartInfo.Arguments = "ProcessStart.cs";
                codeblocks.Start();
            }
            catch(Exception ex)
            {
                setMensagem("Arquivo:" + PATH_DSGRAPH_DOWNLOAD + "\\Exemplos\\exemplos.workspace");
                setMensagem("Erro:" + ex.StackTrace);
                msgBox("Exibição dos exemplos");
            }

        }

        /**
         * Inicia a instalação do CodeBlocks
         * */
        private void instalarCodeBlocks()
        {

            Process codeblocks = new Process();
            setMensagem("Iniciando o processo de instalação do CodeBlocks...");

            codeblocks.StartInfo.FileName = PATH_DSGRAPH_DOWNLOAD + "\\codeblocks-10.05mingw-setup.exe";
            codeblocks.StartInfo.Arguments = "ProcessStart.cs";

            codeblocks.Start();
            codeblocks.WaitForExit();

            setMensagem("Instalação concluída!");
        }

        /**
         * Mensagem padrão para falhas 
         * */
        private void msgBox(String msg)
        {

            MessageBox.Show("A instalação falhou quando tentava executar a seguinte operação:" + msg +
                            "\n Verifique os seguintes itens e tente novamente:" +
                            "\n  - Que você esteja conectado a internet;" +
                            "\n -  Que você executou este programada como Administrador ou utilizando um usuário que possui permissões de Administrador"
                             , "DSGraph", MessageBoxButtons.OK, MessageBoxIcon.Error);

            btnInstall.Enabled = true;
            btnAtualizar.Enabled = true;
            this.UseWaitCursor = false;

            setProgressBarValue(0);

            setMensagem("Instalação abortada!");

            Application.DoEvents();

        }


        /**
         * Inicializa componentes
         * */
        private void init()
        {
            textMsgs.Text = "";
            me = this;
            pb = progressBar;
            setProgressBarValue(0);

        }

        /**
         * 
         * */
        private bool checkPermissoes()
        {
            String arqProgramas = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles);
            String windowsFolder = Environment.GetFolderPath(Environment.SpecialFolder.System);
            String pastaTeste = "\\testedsgraph";
            try
            {
                Directory.CreateDirectory(arqProgramas + pastaTeste);
                Directory.Delete(arqProgramas + pastaTeste);

                Directory.CreateDirectory(windowsFolder + pastaTeste);
                Directory.Delete(windowsFolder + pastaTeste);

            }
            catch (UnauthorizedAccessException ex)
            {
                MessageBox.Show("O programa encontrou as seguintes pendências: \n  - Você não utilizou a opção: Executar como Administrador; \n  - ou não é Administrador do seu computador. " +
                          "\n O programa só pode continuar se esta condição for satisfeita. Verifique e tente novamente!"
                           , "DSGraph", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);

                return false;

            }


            return true;
        }

        private void btnInstall_Click(object sender, EventArgs e)
        {
            btnInstall.Enabled = false;
            btnAtualizar.Enabled = false;
            this.UseWaitCursor = true;

            init();

            if (!checkPermissoes())
            {
                btnInstall.Enabled = true;
                btnAtualizar.Enabled = true;
                this.UseWaitCursor = false;
                Application.DoEvents();
                return;
            }



            try
            {
                verificaPastaDownload();
            }
            catch (Exception err)
            {
                setMensagem("Erro:" + err.StackTrace);
                msgBox(" Acesso ao disco C:\temp");
                return;
            }

            try
            {
                //Baixar o CodeBlocks?!
                if (chkCodeBlocks.Checked)
                {
                    downloadCodeBlocks();
                }
                else
                {
                    try
                    {
                        downloadAllegro();
                    }
                    catch (Exception err)
                    {
                        setMensagem("Erro:" + err.StackTrace);
                        msgBox("Download da Allegro");
                        return;
                    }
                }

            }
            catch (Exception err)
            {
                setMensagem("Erro:" + err.StackTrace);
                msgBox("Download do CodeBlocks");
                return;
            }




        }

        private void btnAtualizar_Click(object sender, EventArgs e)
        {
            btnInstall.Enabled = false;
            btnAtualizar.Enabled = false;
            textMsgs.Text = "";
            this.UseWaitCursor = true;

            init();

            if (!checkPermissoes())
            {
                btnInstall.Enabled = true;
                btnAtualizar.Enabled = true;
                this.UseWaitCursor = false;
                Application.DoEvents();
                return;
            }



            try
            {
                verificaPastaDownload();
            }
            catch (Exception err)
            {
                setMensagem("Erro:" + err.StackTrace);
                msgBox(" Acesso ao disco C:\temp");
                return;
            }

            try
            {
                downloadDSGraph();
            }
            catch (Exception err)
            {
                setMensagem("Erro:" + err.StackTrace);
                msgBox("Download da DSGraph");
                return;
            }

            try
            {

                downloadExemplos();
            }
            catch
            {
                msgBox("Download dos exemplos");
                return;
            }


            try
            {
                localizarCodeBlocks(@"C:\");
            }
            catch (Exception err)
            {
                setMensagem("Erro:" + err.StackTrace);
                msgBox("Localizando a instalação do CodeBlocks");
                return;
            }


            if (PATH_CODEBLOCKS != "")
            {

                try
                {
                    descompactCopyDSGraphLib();
                }
                catch (Exception err)
                {
                    setMensagem("Erro:" + err.StackTrace);
                    msgBox("Descompactando os arquivos da DSGraph");
                    return;
                }

            }


            try
            {
                descompactExemplos();
            }
            catch
            {
                msgBox("Descompactando os exemplos");
                return;
            }



            setMensagem("Instalação/Configuração concluída com exito!");
            MessageBox.Show("Atualização concluída com sucesso!", "DSGraph", MessageBoxButtons.OK, MessageBoxIcon.Information);

            configuraProjetoCodeBlocks();

            iniciarCodeBlocks();

            btnInstall.Enabled = true;
            btnAtualizar.Enabled = true;
            this.UseWaitCursor = false;
            this.Refresh();
            Application.DoEvents();

            
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            iniciarCodeBlocks();
        }

    }
}
