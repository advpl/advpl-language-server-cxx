'use strict';
// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
import * as vscode from 'vscode';
import * as vscodelc from 'vscode-languageclient';

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {
    //const lsPath = "../build/Debug/advpl-language-server-cxx.exe";
    //const lsPath = "/home/vlopes/dev/github/advpl-language-server-cxx/cmake-build-debug/src/advpl_language_server_cxx_bin"
    const lsPath = "C:/Totvs/vscode/c_version/advpl-language-server-cxx/build/Debug/advpl-language-server-cxx.exe"
    const lsArgs: string[] = [];
    const serverOptions: vscodelc.ServerOptions = { command: lsPath, args: lsArgs };

    const clientOptions: vscodelc.LanguageClientOptions = {

        documentSelector: ['prw', 'prx']
        /*uriConverters: {
            // FIXME: by default the URI sent over the protocol will be percent encoded (see rfc3986#section-2.1)
            //        the "workaround" below disables temporarily the encoding until decoding
            //        is implemented properly in clangd
            code2Protocol: (uri: vscode.Uri) : string => uri.toString(true),
            protocol2Code: (uri: string) : vscode.Uri => vscode.Uri.parse(uri)
        }*/
    };

    const advplClient = new vscodelc.LanguageClient('Advpl Language Server', serverOptions, clientOptions);

    console.log('Advpl Language Server is now active!');
    const disposable = advplClient.start();

    advplClient.onReady().then(_ => {
        try {
            let expected = {
                capabilities: {
                    textDocumentSync: 1,
                    completionProvider: { resolveProvider: true, triggerCharacters: ['"', ':'] },
                    hoverProvider: true
                },
                customResults: {
                    "hello": "world"
                }
            };
            //assert.deepEqual(client.initializeResult, expected);
            disposable.dispose();

        } catch (e) {
            disposable.dispose();

        }
    }, e => {
        disposable.dispose();

    });

    context.subscriptions.push(disposable);
}

// this method is called when your extension is deactivated
export function deactivate() {
}