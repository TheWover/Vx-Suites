package com.vvt.prot.command.response;

import com.vvt.prot.CommandCode;

public class SendHeartBeatCmdResponse extends StructureCmdResponse  {
	
	// ServerResponse
	public CommandCode getCommand() {
		return CommandCode.SEND_HEARTBEAT;
	}
}
