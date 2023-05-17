package com.icanfarm.icanfarm.controller;

import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;
import java.io.IOException;

@ServerEndpoint("/api/socket")
public class WebsocketController {
    private Session userSession;

    @OnOpen
    public void onOpen(Session userSession)
    {
        System.out.println("!!!!!!!!!!!Websokcet client connected!");
        this.userSession = userSession;
    }

    @OnClose
    public void onClose() throws IOException
    {
        System.out.println("!!!!!!!!!!!Websokcet close");
    }

    // 모든 클라이언트에게 메시지 전송
    public void broadcast(String message)
    {
        System.out.println("!!!!!!!!!!!Websokcet message broadcast : " + message);
        RemoteEndpoint.Basic basic = this.userSession.getBasicRemote();
        try
        {
            basic.sendText(message);
        } catch (IOException e)
        {
            e.printStackTrace();
        }

    }

}
