import pandas as pd
from argparse import ArgumentParser

pd.options.display.max_columns = 10
pd.options.display.max_rows = 30
pd.options.display.expand_frame_repr = False

def main():
    parser = ArgumentParser()
    parser.add_argument('-i', '--input', required=True)
    args = parser.parse_args()
    analy(args)

def analy(args):
    data_trace_file = args.input
    data_trace = pd.read_csv(data_trace_file, dtype={
        'DISASM': str,
        'ADDR': str,
        'INST': str,
        'DADDR': str,
        'DSIZE': int,
        'DATA': str,
    })
    print(data_trace.head())


if __name__ == '__main__':
    main()
