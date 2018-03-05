#ifndef _NISPROG_H
#define _NISPROG_H

/* state of connection to ECU */
enum npstate_t {
	NP_DISC,	/** disconnected */
	NP_NORMALCONN, /** normal connection to stock firmware */
	NP_NPKCONN /** kernel connection to npkern */
};

extern enum npstate_t npstate;

enum ecutype_t {
	NISECU_UNK,
	NISECU_7055_35,	/** old 350nm part */
	NISECU_7055_18,	/** 180nm */
	NISECU_7058
	};

struct nisecu_t {
	//enum ecutype_t ecutype;	/** decides which flashblock descriptor to use etc */
	uint8_t ecuid[6];		/** ASCIIz */

	const void *keyset;	/** keyset to use */
	const void *flashdev;	/** device descriptor */

} nisecu;


/* public funcs */
void nisecu_cleardata(struct nisecu_t *pne);


/***** CLI command handlers */
int cmd_npconn(int argc, char **argv);
int cmd_npdisc(int argc, char **argv);
int cmd_npconf(int argc, char **argv);
int cmd_setdev(int argc, char **argv);
int cmd_setkeys(int argc, char **argv);
int cmd_kspeed(int argc, char **argv);
int cmd_runkernel(int argc, char **argv);
int cmd_stopkernel(int argc, char **argv);
int cmd_initk(int argc, char **argv);
int cmd_dumpmem(int argc, char **argv);
int cmd_watch(int argc, char **argv);
int cmd_flverif(int argc, char **argv);
int cmd_flblock(int argc, char **argv);
int cmd_flrom(int argc, char **argv);
int cmd_npt(int argc, char **argv);
int cmd_fleep(int argc, char **argv);
int cmd_dmeep(int argc, char **argv);
int cmd_wreep(int argc, char **argv);
int cmd_rdeep(int argc, char **argv);
int cmd_wreep32(int argc, char **argv);
int cmd_rdeep32(int argc, char **argv);

#endif
