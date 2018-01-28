'use strict';
// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
import * as vscode from 'vscode';
import * as vscodelc from 'vscode-languageclient';

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {
    const lsId: string = 'advpl-ls';
    const lsPath: string = vscode.workspace.getConfiguration(lsId).get('bin');
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

    const advplClient = new vscodelc.LanguageClient(lsId, 'AdvPL Language Server', serverOptions, clientOptions);
    const disposable = advplClient.start();

    context.subscriptions.push(disposable);
}

// this method is called when your extension is deactivated
export function deactivate() {
}
